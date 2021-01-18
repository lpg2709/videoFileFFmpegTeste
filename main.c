// std includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <stdarg.h>

// ffmpeg includes
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

/* 
 * Main components
 *
 * Format (Container) - a wrapper, providing sync, metadata and muxing for the streams.
 * Stream - a continuous stream (audio or video) of data over time.
 * Codec - defines how data are enCOded (from Frame to Packet) and DECoded (from Packet to Frame).
 * Packet - are the data (kind of slices of the stream data) to be decoded as raw frames.
 * Frame - a decoded raw frame (to be encoded or filtered).
 */

/*
 * FFmpeg libav process of decoding a video (and audio)
 *
 * video.mp4 -> AVFormatContext(Read the Headers) -> AVStream (Steams in file) 
 *           -> AVPacket (For each stream, slices of data) -> AVCodec (Decode all pices of packets) 
 *           -> AVFrame (Uncompresed frame)
 */


static void logging(const char *fmt, ...){
	va_list args;
	fprintf( stderr, "LOG: " );
	va_start( args, fmt );
	vfprintf( stderr, fmt, args );
	va_end( args );
	fprintf( stderr, "\n" );
}

int main(int argc, const char **argv){
	if(argc < 2){
		printf("Specify a midia file.\n");
		return -1;
	}

	logging("initializing all the containers, codecs and protocols.");

	AVFormatContext *pFormatContext = avformat_alloc_context(); // Allocate memory to format container
	if(!pFormatContext){
		logging("Error, allocate memory for Format Context");
		return -1;
	}

	logging("opening the input file (%s) and loading format (container) header", argv[1]);

	if(avformat_open_input(&pFormatContext, argv[1], NULL, NULL) !=0){ // Open the file and read its header
		logging("Erro, open the file");
		return -1;
	}

	logging("format: %s, duration: %lld us, bit_rate: %lld", pFormatContext->iformat->name, pFormatContext->duration, pFormatContext->bit_rate);

	logging("finding stream info from format");

	if(avformat_find_stream_info(pFormatContext, NULL) < 0){
		logging("ERROR could not get the stream info");
	    return -1;
	}

	AVCodec *pCodec = NULL;

	AVCodecParameters *pCodecParameters = NULL;
	int video_stream_index = -1;

	int i;

	for(i = 0; i < pFormatContext->nb_streams; i++){
		AVCodecParameters *pLocalCodecParameters = NULL;

		pLocalCodecParameters = pFormatContext->streams[i]->codecpar;

		logging("AVStream->time_base before open coded %d/%d", pFormatContext->streams[i]->time_base.num, pFormatContext->streams[i]->time_base.den);
	    logging("AVStream->r_frame_rate before open coded %d/%d", pFormatContext->streams[i]->r_frame_rate.num, pFormatContext->streams[i]->r_frame_rate.den);
	    logging("AVStream->start_time %" PRId64, pFormatContext->streams[i]->start_time);
	    logging("AVStream->duration %" PRId64, pFormatContext->streams[i]->duration);

		logging("finding the proper decoder (CODEC)");
	}

	avformat_close_input(&pFormatContext);

	return 0;
}

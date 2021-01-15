cmake_minimum_required(VERSION 3.0)

project(videoFileFFmpegTeste C)

add_subdirectory(lib/ffmpeg)

list(APPEND SOURCES main.c)
list(APPEND CLINKS "-lm")

add_executable(videoFileFFmpegTeste ${SOURCES})

target_link_libraries(videoFileFFmpegTeste FFmpeg ${CLINKS})

# videoFileFFmpegTeste

Teste FFmpeg libraries, libAV.

## Dependencies

- FFmpeg libs

- C compiler (GCC) > 9.3.0

- CMake > 3.0

- pkg-config > 0.29.1

## Scripts

- ```run.sh``` - Execute the program with the file

- ```clear.sh``` - Clean the folder

- ```compile_debug.sh``` - Compile the code, for debug.

## Install FFmpeg

I recomand compile direct from source code.I have some problemes with the packages install.

```bash
git clone https://git.ffmpeg.org/ffmpeg.git ffmpeg
cd ffmpeg
./configure
make
make install
```


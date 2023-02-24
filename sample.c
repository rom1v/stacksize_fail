#include <SDL2/SDL.h>
#include <libavdevice/avdevice.h>

int main(void) {
    avdevice_register_all();

    if (SDL_Init(SDL_INIT_AUDIO)) {
        fprintf(stderr, "SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_AudioSpec desired = {
        .freq = 48000,
        .format = AUDIO_S16LSB,
        .channels = 2,
        .samples = 4096,
    };
    SDL_AudioSpec obtained;

    SDL_AudioDeviceID device =
        SDL_OpenAudioDevice(NULL, 0, &desired, &obtained, 0);
    printf("device = %d\n", device);
    if (!device) {
        fprintf(stderr, "%s\n", SDL_GetError());
        return -1;
    }

    SDL_CloseAudioDevice(device);

    return 0;
}

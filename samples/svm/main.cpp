#include <thread>
#include <chrono>
#include <SDL.h>
#include "filamentapp/NativeWindowHelper.h"
#include "filamentapp/data/CustomCar.h"
#include "controller/RenderApp.h"

#if !defined(WIN32)
#if defined(FILAMENT_SUPPORTS_WAYLAND)
#    include <SDL_syswm.h>
#endif
#else
#    include <SDL_syswm.h>
#    include <utils/unwindows.h>
#endif

int main() {
    SDL_Init(SDL_INIT_EVENTS);

    std::int32_t const x = SDL_WINDOWPOS_CENTERED;
    std::int32_t const y = SDL_WINDOWPOS_CENTERED;
    std::int32_t const w = 800;
    std::int32_t const h = 600;
    std::uint32_t const windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;

    SDL_Window* const mWindow = SDL_CreateWindow("SVM", x, y, (int) w, (int) h, windowFlags);

    void* nativeWindow = ::getNativeWindow(mWindow);;

    SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
    SDL_Window* sdlWindow = mWindow;

    auto app = nxt::svm::RenderApp::create(0, nativeWindow);
    app->surfaceChanged(0, w, h, nativeWindow);
    app->setRenderData(std::make_shared<nxt::svm::CustomCarRenderData>(
            "/Users/thanhlong/Desktop/Projects/svm/surround-view-monitoring-APP/SVM/app/src/main/assets"));

    bool mClosed = false;
    while (!mClosed) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    mClosed = true;
                    break;
                default:
                    break;
            }
        }
    }

    app->surfaceDestroyed();
    nxt::svm::RenderApp::destroy(0);

    SDL_DestroyWindow(mWindow);
    SDL_Quit();

    return 0;
}

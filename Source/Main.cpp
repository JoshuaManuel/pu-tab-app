#include "ui/MainApplication.hpp"
#include <switch.h>
#include <iostream>
#include <string>
#include "util/debug.hpp"
#include "cfg/cfg.hpp"

// If you would like to initialize and finalize stuff before or after Plutonium, you can use libnx's userAppInit/userAppExit

extern "C" void userAppInit()
{
    romfsInit(); // initialize romfs so we can use it!
    socketInitializeDefault(); // initialize sockets for libcurl
    nxlinkStdio(); // reroute print statements to nxlink

    cfg::loadStrings("en");

}

extern "C" void userAppExit()
{
    socketExit();
}

// Main entrypoint
int main()
{
    debug::test();

    // First create our renderer, where one can customize SDL or other stuff's initialization.
    auto renderer = pu::ui::render::Renderer::New(pu::ui::render::RendererInitOptions(SDL_INIT_EVERYTHING, pu::ui::render::RendererHardwareFlags).WithIMG(pu::ui::render::IMGAllFlags).WithMixer(pu::ui::render::MixerAllFlags).WithTTF());

    // Create our main application from the renderer
    auto main = ui::MainApplication::New(renderer);

    // Prepare out application. This MUST be called or Show() will exit and nothing will be rendered.
    main->Prepare();

    // Show -> start rendering in an "infinite" loop
    // If wou would like to show with a "fade in" from black-screen to the UI, use instead ->ShowWithFadeIn();
    main->ShowWithFadeIn();

    // Exit homebrew (Plutonium will handle all disposing of UI and renderer/application, don't worry!

    return 0;
}
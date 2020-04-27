//#include <switch.h>
#include "ui/MainApplication.hpp"
#include "ui/imagePage.hpp"

#define COLOR(hex) pu::ui::Color::FromHex(hex)

using namespace pu::ui::elm;

namespace ui {
    extern MainApplication *mainApp;

    //Add new elements to page here
    ImagePage::ImagePage() : Layout::Layout () {
        //Declare elements here
        this->fafsa = Image::New(410, 190, "romfs:/images/fafsa.jpg");

        //Add items
        this->Add(this->fafsa);
    }

    //Handle input
    void ImagePage::onInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {

        //Exit if needed
        if (((Down & KEY_PLUS) || (Down & KEY_MINUS)) && mainApp->IsShown()) {
            mainApp->CloseWithFadeOut();
        }

        //Handle menu input

        //Go back
        if (Down & KEY_B) {
            mainApp->LoadLayout(mainApp->mainPage);
        }
    }
}
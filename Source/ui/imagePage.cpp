//#include <switch.h>
#include "ui/MainApplication.hpp"
#include "ui/imagePage.hpp"
#include <string>

#define COLOR(hex) pu::ui::Color::FromHex(hex)

using namespace pu::ui::elm;

std::string buttons = "A:\ue0e0  B:\ue0e1  X:\ue0e2  Y:\ue0e3   L:\ue0e4  R:\ue0e5  ZL:\ue0e6  ZR:\ue0e7 SL:\ue0e8  SR:\ue0e9  D-pad:\ue0ea  D-UP:\ue0ebD-DOWN:\ue0ec  D-LEFT:\ue0ed  D-RIGHT:\ue0ee  PLUS-CIRCLE:\ue0efMINUS-CIRCLE:\ue0f0  PLUS:\ue0f1  MINUS:\ue0f2   POWER:\ue0f3  HOME:\ue0f4   SCREENSHOT:\ue0f5";


namespace ui {
    extern MainApplication *mainApp;

    //Add new elements to page here
    ImagePage::ImagePage() : Layout::Layout () {

        //Declare elements
        this->fafsa = Image::New(410, 190, "romfs:/images/fafsa.jpg");
        this->buttonsText = TextBlock::New(0, 400, buttons);

        //Add items
        this->Add(this->fafsa);
        this->Add(this->buttonsText);
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
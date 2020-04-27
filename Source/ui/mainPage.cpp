#include <switch.h>
#include "ui/mainPage.hpp"
#include "ui/MainApplication.hpp" // Needed to reference externMainApplication

#define COLOR(hex) pu::ui::Color::FromHex(hex)

using namespace pu::ui::elm; // Allows us to include Plutonium elements found in this namespace (like MenuItem and Menu) without having to type "pu::ui::elm::MenuItem" or something similar each time they are referenced

namespace ui { // All below code is in this namespace
    extern MainApplication *mainApp;

    // Add new elements to main page
    MainPage::MainPage() : Layout::Layout() {
        printf("hello");
        this->SetBackgroundColor(COLOR("#670000FF"));

        this->optionMenu = Menu::New(0, 95, 1280, COLOR("#67000000"), 94, 6);
        this->optionMenu->SetOnFocusColor(COLOR("#00000033"));
        this->optionMenu->SetScrollbarColor(COLOR("#170909FF"));

        this->firstItem = MenuItem::New("First item: Press + to quit");
        this->firstItem->SetColor(COLOR("#FFFFFFFF"));

        this->secondItem = MenuItem::New("Second item");
        this->secondItem->SetColor(COLOR("#FFFFFFFF"));

        this->thirdItem = MenuItem::New("Select this to exit"); //not setting this color

        this->optionMenu->AddItem(this->firstItem);
        this->optionMenu->AddItem(this->secondItem);
        this->optionMenu->AddItem(this->thirdItem);

        this->Add(this->optionMenu);
    }

    // Create functions to call when menuItem pressed
    void MainPage::firstMenuItemClick() {
        printf("Clicked first menuItem\n");
    }

    void MainPage::secondMenuItemClick() {
        printf("Clicked second menuItem\n");
    }

    void MainPage::thirdMenuItemClick() {
        mainApp->FadeOut();
        mainApp->Close();
    }

    // Handle mainPage input
    void MainPage::onInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {

        //Exit if needed
        if (((Down & KEY_PLUS) || (Down & KEY_MINUS) || (Down & KEY_B)) && mainApp->IsShown()) {
            mainApp->CloseWithFadeOut();
        }

        // Handle menu input
        if ((Down & KEY_A) || (Up & KEY_TOUCH)) {
            switch (this->optionMenu->GetSelectedIndex()) {
                case 0:
                    this->firstMenuItemClick();
                    break;
                case 1:
                    this->secondMenuItemClick();
                    break;
                case 2:
                    this->thirdMenuItemClick();
                default:
                    break;
            }
        }
    }
}
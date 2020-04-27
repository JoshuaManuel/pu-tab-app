#include "ui/MainApplication.hpp"

namespace ui {
    MainApplication *mainApp; //Initially declared here

    void MainApplication::OnLoad() {
        mainApp = this;

        //Create new instances of each used page. Add them here
        this->mainPage = MainPage::New();
        this->imagePage = ImagePage::New();

        /*
        Bind the onInput functions of each page.
        Alternatively, you can declare an anonymous (aka lambda) function. See line 26: https://github.com/XorTroll/Plutonium/blob/master/Example/Source/MainApplication.cpp
        */
        this->mainPage->SetOnInput(std::bind(&MainPage::onInput, this->mainPage, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

        this->LoadLayout(this->mainPage); //Load the initial page
    }
}
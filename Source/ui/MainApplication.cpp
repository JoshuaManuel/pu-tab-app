#include "ui/MainApplication.hpp"

namespace ui {
    MainApplication *mainApp;

    void MainApplication::OnLoad() {
        mainApp = this;
        this->mainPage = MainPage::New();
        this->LoadLayout(this->mainPage);
    }
}
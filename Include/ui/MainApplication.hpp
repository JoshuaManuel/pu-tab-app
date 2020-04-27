
#pragma once

// Include Plutonium's main header
#include <pu/Plutonium>

//Include each page's header file here
#include "ui/mainPage.hpp"
#include "ui/imagePage.hpp"

namespace ui {
    class MainApplication : public pu::ui::Application {
        public:
            using Application::Application;
            PU_SMART_CTOR(MainApplication)
            void OnLoad() override;

            //Update new pages here
            MainPage::Ref mainPage;
            ImagePage::Ref imagePage;
    };
}

#pragma once

// Include Plutonium's main header
#include <pu/Plutonium>

//Include each page's header file here
#include "ui/mainPage.hpp"

namespace ui {
    class MainApplication : public pu::ui::Application {
        public:
            using Application::Application;
            PU_SMART_CTOR(MainApplication)
            void OnLoad() override;

            MainPage::Ref mainPage;
    };
}
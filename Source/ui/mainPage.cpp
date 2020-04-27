#include <switch.h>
#include "ui/mainPage.hpp"

#define COLOR(hex) pu::ui::Color::FromHex(hex)

using namespace pu::ui::elm;

MainPage::MainPage() : Layout::Layout() {
    printf("hello");
    this->SetBackgroundColor(COLOR("#670000FF"));
}

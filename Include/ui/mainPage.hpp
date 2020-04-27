#pragma once
#include <pu/Plutonium>

using namespace pu::ui::elm;

namespace ui {
    class MainPage : public pu::ui::Layout {
    public:
        MainPage();
        PU_SMART_CTOR(MainPage)
        
        void firstMenuItemClick();
        void secondMenuItemClick();
        void thirdMenuItemClick();
        void onInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
    private:
        Menu::Ref optionMenu;
        MenuItem::Ref firstItem;
        MenuItem::Ref secondItem;
        MenuItem::Ref thirdItem;
    };
}
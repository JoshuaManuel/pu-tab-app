#pragma once
#include <pu/Plutonium>

using namespace pu::ui::elm;

namespace ui {
    class ImagePage : public pu::ui::Layout {
    public:
        ImagePage();
        PU_SMART_CTOR(ImagePage)
        
        void onInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
    private:
        Image::Ref fafsa;
    };
}
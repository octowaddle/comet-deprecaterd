#include <comet/graphics/window.hpp>

int main()
{
    comet::Window window(1280, 720, "My Epic Window");

    while (!window.close_requested()) window.update();

    return 0;
}

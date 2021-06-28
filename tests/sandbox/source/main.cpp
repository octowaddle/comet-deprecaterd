#include <comet/graphics/window.hpp>
#include <comet/events/event.hpp>
#include <iostream>

using namespace comet;

int main()
{
    Window window(1280, 720, "comet");

    while (!window.close_requested())
    {
        window.update();

        while (window.events_queued())
        {
            auto event = window.poll_event();

            if (event.get_type() == Event::Type::WindowResize)
            {
                auto resize_event = event.as_window_resize_event();\
                std::cout << "window resize event: " << resize_event.get_width() << " " << resize_event.get_height() << "\n";
            }
        }
    }

    return 0;
}

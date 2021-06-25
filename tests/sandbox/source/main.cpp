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
            Event event = window.poll_event();

            if (event.get_type() == Event::Type::Window)
            {
                WindowEvent window_event = event.as_window_event();

                if (window_event.get_type() == WindowEvent::Type::Resize)
                {
                    WindowResizeEvent window_resize_event = window_event.as_window_resize_event();
                    std::cout << "WindowResizeEvent " << window_resize_event.get_width() << " " << window_resize_event.get_height() << "\n";
                }
            }
        }
    }

    return 0;
}

#include "comet/events/key_events/key_pressed_event.hpp"
#include "comet/events/key_events/key_released_event.hpp"
#include "comet/events/window_events/window_resize_event.hpp"
#include <comet/graphics/window.hpp>
#include <comet/events/event.hpp>
#include <iostream>

using namespace comet;

int main()
{
    Window window(1280, 720, "comet");
    bool running = true;

    while (running)
    {
        window.update();

        while (window.events_queued())
        {
            auto event = window.poll_event();

            switch (event.get_type())
            {
                case Event::Type::KeyPressed:
                {
                    KeyPressedEvent e = event.as_key_pressed_event();
                    std::cout << "key pressed (key code: " << e.get_key_code() << ")\n";
                    break;
                }
                case Event::Type::KeyReleased:
                {
                    KeyReleasedEvent e = event.as_key_released_event();
                    std::cout << "key released (key code: " << e.get_key_code() << ")\n";
                    break;
                }
                case Event::Type::WindowClose:
                {
                    running = false;
                    std::cout << "window close requested\n";
                    break;
                }
                case Event::Type::WindowResize:
                {
                    WindowResizeEvent e = event.as_window_resize_event();
                    std::cout << "window resized (width: " << e.get_width() << ", height: " << e.get_height() << ")\n";
                    break;
                }
            }
        }
    }

    return 0;
}

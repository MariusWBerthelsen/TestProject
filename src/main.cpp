// src/main.cpp
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "LoginScreen.h"
#include "MouseUtility.h"

using namespace ImGui::SFML;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(640, 480), "Login Screen");
    window.setFramerateLimit(60);
    Init(window);

    LoginScreen loginScreen;
    Clock deltaClock;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            ProcessEvent(event);
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        Update(window, deltaClock.restart());

        DisplayMousePosition(window);

        loginScreen.Display(window);

        window.clear();
        Render(window);
        window.display();
    }

    Shutdown();
}

// src/LoginScreen.cpp
#include "LoginScreen.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <cstring>

using namespace std;
using namespace ImGui;

void LoginScreen::Display(sf::RenderWindow& window) {
    static char username[128] = "";
    static char password[128] = "";
    static bool loginSuccess = false;

    Begin("Login");

    InputText("Username", username, sizeof(username));
    InputText("Password", password, sizeof(password), ImGuiInputTextFlags_Password);

    if (Button("Login")) {
        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            loginSuccess = true;
        }
    }

    if (loginSuccess) {
        Text("Login successful!");
    }

    End();
}

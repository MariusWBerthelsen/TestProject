// src/MouseUtility.cpp
#include "MouseUtility.h"
#include <imgui.h>

using namespace sf;

void DisplayMousePosition(const RenderWindow& window) {
    Vector2i mousePos = Mouse::getPosition(window);
    char mousePosStr[32];
    sprintf_s(mousePosStr, sizeof(mousePosStr), "Mouse Pos: X:%d Y:%d", mousePos.x, mousePos.y);

    ImGui::SetNextWindowPos(ImVec2(static_cast<float>(window.getSize().x - 200), 10.0f), ImGuiCond_Always);
    ImGui::Begin("Mouse Position", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::Text("%s", mousePosStr);
    ImGui::End();
}
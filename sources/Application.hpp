#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include <omp.h>

#include <iostream>

class Application
{
public:
    explicit Application(sf::ContextSettings const& settings = sf::ContextSettings());

    ~Application();

    void run();

private:
    void processEvents();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    void update(sf::Time deltaTime);

    void render(sf::Time deltaTime);

public:
    static inline uint32_t const WindowWidth = 800;
    static inline uint32_t const WindowHeight = 600;

    static inline std::string const WindowTitle{"Template Application"};

    static inline sf::Uint32 const WindowStyle = sf::Style::Close;

    static inline uint32_t const FramesPerSecond = 60;
    static inline sf::Time const TimePerFrame{sf::seconds(1.f / static_cast<float>(FramesPerSecond))};

private:
    sf::RenderWindow mWindow;
};
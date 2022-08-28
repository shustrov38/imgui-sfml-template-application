#include "Application.hpp"

Application::Application(sf::ContextSettings const& settings)
    : mWindow(sf::VideoMode(WindowWidth, WindowHeight),
              WindowTitle,
              WindowStyle,
              settings)
{
    std::cout << "OPENMP " << _OPENMP << std::endl;
    std::cout << "IMGUI " << IMGUI_VERSION << std::endl;
    std::cout << "SFML " << SFML_VERSION_MAJOR << "." << SFML_VERSION_MINOR << "." << SFML_VERSION_PATCH << std::endl;
    std::cout << "SETTINGS " << settings.majorVersion << "." << settings.minorVersion << std::endl;

    ImGui::SFML::Init(mWindow);
}

Application::~Application()
{
    ImGui::SFML::Shutdown();
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render(timeSinceLastUpdate);
    }
}

void Application::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    // TODO
}

void Application::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            break;
        }
    }
}

void Application::update(sf::Time deltaTime)
{
    // TODO
}

void Application::render(sf::Time deltaTime)
{
    mWindow.clear();
    ImGui::SFML::Update(mWindow, deltaTime);
    ImGui::ShowDemoWindow();

    // TODO

    ImGui::GetDrawData();
    ImGui::SFML::Render(mWindow);
    mWindow.display();
}
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode({1920, 1080}), "Title");
    CircleShape circle(10.f);
    circle.setFillColor(Color::White);
    circle.setOrigin(Vector2f(50.f, 50.f));
    circle.setPosition(Vector2f(400.f, 300.f));

    float speed = 1000.f; // pixels per second
    Clock clock;
    // TEST

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        while (auto event = window.pollEvent())
            if (event->is<Event::Closed>())
                window.close();

        if (Keyboard::isKeyPressed(Keyboard::Key::W))
            circle.move(Vector2f(0.f, -speed * deltaTime));
        if (Keyboard::isKeyPressed(Keyboard::Key::S))
            circle.move(Vector2f(0.f, speed * deltaTime));
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
            circle.move(Vector2f(-speed * deltaTime, 0.f));
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
            circle.move(Vector2f(speed * deltaTime, 0.f));

        window.clear(Color(0, 0, 0));
        window.draw(circle);
        window.display();
    }
    return 0;
}
#include <ctime>
#include <vector>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

constexpr int WIDTH = 1200, HEIGHT = 800, CELL = 20;

enum Directions { UP, DOWN, LEFT, RIGHT };

struct Point {
    int x, y;
};

std::vector<Point> snake = {{(WIDTH / CELL) / 2, (HEIGHT / CELL) / 2}};
Point food = {15, 10};
Directions dir = RIGHT;
bool gameOver = false;

void drawRect(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x * CELL, y * CELL);
    glVertex2f((x + 1) * CELL, y * CELL);
    glVertex2f((x + 1) * CELL, (y + 1) * CELL);
    glVertex2f(x * CELL, (y + 1) * CELL);
    glEnd();
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        if ((key == GLFW_KEY_W or key == GLFW_KEY_UP) and dir != DOWN)
            dir = UP;
        if ((key == GLFW_KEY_D or key == GLFW_KEY_RIGHT)
            and dir != LEFT)
            dir = RIGHT;
        if ((key == GLFW_KEY_S or key == GLFW_KEY_DOWN)
            and dir != UP)
            dir = DOWN;
        if ((key == GLFW_KEY_A or key == GLFW_KEY_LEFT)
            and dir != RIGHT)
            dir = LEFT;
    }
}

void moveSnake() {
    Point head = snake.front();
    switch (dir) {
        case UP: head.y--;
            break;
        case DOWN: head.y++;
            break;
        case LEFT: head.x--;
            break;
        case RIGHT: head.x++;
            break;
    }

    if (head.x < 0 || head.x >= WIDTH / CELL || head.y < 0 || head.y >= HEIGHT / CELL) {
        gameOver = true;
    }

    for (auto &segment: snake) {
        if (segment.x == head.x && segment.y == head.y) {
            gameOver = true;
            break;
        }
    }

    snake.insert(snake.begin(), head);
    if (head.x == food.x && head.y == food.y) {
        food.x = rand() % (WIDTH / CELL);
        food.y = rand() % (HEIGHT / CELL);
    } else {
        snake.pop_back();
    }
}


int main() {
    srand((unsigned) time(0));

    if (!glfwInit()) return -1;

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Snake", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);

    double lastTime = glfwGetTime(), timer = 0, delay = 0.1;
    while (!glfwWindowShouldClose(window)) {
        double currentTime = glfwGetTime();
        if (currentTime - lastTime > delay) {
            moveSnake();
            lastTime = currentTime;
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (gameOver) {
            std::cout << "Game Over! Your score: " << snake.size() - 1 << std::endl;
            break;
        }

        drawRect(food.x, food.y, 1, 0, 0);
        for (auto &s: snake) {
            drawRect(s.x, s.y, 0, 1, 0);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#include "core/Game.hpp"

using namespace pk;

Game::~Game()
{
    delete m_window;
}

void Game::init()
{
    if(!(m_gameState == gameState::s_uninitialized))
    {
        printf("Game not in an uninitialized state!");
        return;
    }

    //initialize window
    SDL_Rect rect;
    rect.w = 800;
    rect.h = 600;
    rect.x = 0;
    rect.y = 0;

    m_window = new Window("Game time!", glm::ivec2(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED), rect.w, rect.h, SDL_WINDOW_OPENGL);
    m_window->setWindowRect(rect);

    m_running = true;

    while(isRunning())
    {
        run();
    }
}

Game& Game::getInstance()
{
    static Game* gameInstance = new Game;
    return *gameInstance;
}

void Game::run()
{
    switch(m_gameState)
    {
        case gameState::s_uninitialized:
        {
            m_running = false;
        }
        break;
        case gameState::s_quit:
        {
            m_running = false;
        }
        break;
        default:
        break;
    }
}

//static member variable instantiation
//instantiate screen states...
Window* Game::m_window = nullptr;//Window("Game time!", glm::ivec2(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED), 800, 600, SDL_WINDOW_OPENGL);

ScreenState * Game::m_state = nullptr;
Uint32 Game::m_gameState = Game::gameState::s_uninitialized;
bool Game::m_running = false;

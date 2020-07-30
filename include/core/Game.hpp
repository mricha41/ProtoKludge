#ifndef GAME_HPP
#define GAME_HPP

#include "core/Window.hpp"
#include "states/ScreenState.hpp"

namespace pk
{

///////////////////////////////////////////////////////////////
/// \class Game
/// \brief Class for storing and managing all game data and states.
/// Game is implemented as a Singleton and also uses the State pattern
/// along with ScreenState subclasses.
//////////////////////////////////////////////////////////////
class Game
{
    private:
        //Inaccessible constructor
        /// \fn Game()
        /// \brief Inaccessible - Game is a Singleton.
        Game(){};
    public:
        virtual ~Game();

        /////////////////////////////////////////////
        /// \enum gameState
        /// \brief Internal states of the game.
        /////////////////////////////////////////////
        enum gameState
        {
            s_uninitialized,
            s_quit
        };

        //These functions are deleted so that
        //copies cannot be made.
        //Singleton pattern depends on this.
        /// \fn Game(Game const&) = delete;
        /// \brief Inaccessible - Game is a Singleton.
        Game(Game const&) = delete;
        /// \fn void operator=(Game const&) = delete;
        /// \brief Inaccessible - Game is a Singleton.
        void operator=(Game const&) = delete;

        ////////////////////////////////////////////////////
        /// \fn static void init()
        /// \brief Initialization routine for Game ScreenStates.
        ////////////////////////////////////////////////////
        static void init();

        ////////////////////////////////////////////////////
        /// \fn static Game& getInstance()
        /// \brief Retrieve the Singleton Game object.
        ////////////////////////////////////////////////////
        static Game& getInstance();

        ////////////////////////////////////////////////////
        /// \fn static Window * const getWindow()
        /// \brief Retrieve the SDL window from the Game object.
        ////////////////////////////////////////////////////
        static Window * const getWindow(){return m_window;};

        /////////////////////////////////////////////////////
        /// \fn static void run()
        /// \brief Runs the game - call to get everything going.
        /////////////////////////////////////////////////////
        static void run();

        /////////////////////////////////////////////////////
        /// \fn static void setScreenState(ScreenState * const state)
        /// \brief Set the current ScreenState of the Game.
        /////////////////////////////////////////////////////
        static void setScreenState(ScreenState * const state){ m_state = state; };

        /////////////////////////////////////////////////////
        /// \fn static bool isRunning()
        /// \brief Check if the Game is running.
        /// \return bool
        /////////////////////////////////////////////////////
        static bool isRunning(){ return m_running; };

    private:
        static Window *m_window; ///< Window object for context and rendering.
        static ScreenState *m_state; ///< Current state instance.
        static Uint32 m_gameState; ///< Game object state (not screen state...but related).
        static bool m_running; ///< Check if Game is running.
};

} // end namespace pk

#endif // GAME_HPP

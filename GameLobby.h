#ifndef GAME_LOBBY_H
#define GAME_LOBBY_H

#include <SDL.h>
#include <vector>

class GameLobby{
public:
    GameLobby();
    ~GameLobby();
    void init(const char* title, int x, int y, int width, int height, bool fullscreen);
    void handle_events();
    void update();
    void render();
    void clean();
    bool running() { return is_running; }
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool is_running;
    int button_width;
    int button_height;
    int new_game_x;
    int new_game_y;
    int options_x;
    int options_y;
    int multiplayer_x;
    int multiplayer_y;
    std::vector<SDL_Rect*> buttons;
};

#endif
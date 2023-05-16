#include "gamelobby.h"

GameLobby::GameLobby() {}
GameLobby::~GameLobby() {}

void GameLobby::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
    Uint32 flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        is_running = true;
        button_width = 200;
        button_height = 50;
        new_game_x = (width - button_width) / 2;
        new_game_y = (height - button_height * 3) / 2;
        options_x = new_game_x;
        options_y = new_game_y + button_height;
        multiplayer_x = new_game_x;
        multiplayer_y = new_game_y + button_height * 2;
        buttons.push_back(new SDL_Rect({ new_game_x, new_game_y, button_width, button_height }));
        buttons.push_back(new SDL_Rect({ options_x, options_y, button_width, button_height }));
        buttons.push_back(new SDL_Rect({ multiplayer_x, multiplayer_y, button_width, button_height }));
    }
    else {
        is_running = false;
    }
}

void GameLobby::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        is_running = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        for (int i = 0; i < buttons.size(); i++) {
            if (SDL_PointInRect(&event.button, buttons[i])) {
                if (i == 0) {
                    // Handle new game button click
                }
                else if (i == 1) {
                    // Handle options button click
                }
                else {
                    // Handle multiplayer button click
                }
            }
        }
        break;
    default:
        break;
    }
}

void GameLobby::update() {
    // Update game logic here
}

void GameLobby::render() {
    SDL_RenderClear(renderer);
    // Render game graphics here

    // Render buttons
    SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
    for (int i = 0; i < buttons.size(); i++) {
        SDL_RenderFillRect(renderer, buttons[i]);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, buttons[0]);
    SDL_RenderDrawRect(renderer, buttons[1]);
    SDL_RenderDrawRect(renderer, buttons[2]);
    SDL_RenderPresent(renderer);
}

void GameLobby::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

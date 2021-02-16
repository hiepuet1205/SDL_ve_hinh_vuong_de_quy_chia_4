#include <iostream>
#include <SDL.h>
#include "ham_ve.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";
const double ratio = 2.2;

void draw_a_square(double x, double y, double size, SDL_Renderer* renderer){
    SDL_Rect rect;
    rect.x = x - size/2;
    rect.y = y - size/2;
    rect.w = size;
    rect.h = size;

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_RenderPresent(renderer);

}

void draw(int n, double x, double y, double size, SDL_Renderer* renderer){
    if (n==0) return;

    draw_a_square(x, y, size, renderer);

    draw(n-1, x - size/2, y - size/2, size/ratio, renderer);
    draw(n-1, x - size/2, y + size/2, size/ratio, renderer);
    draw(n-1, x + size/2, y - size/2, size/ratio, renderer);
    draw(n-1, x + size/2, y + size/2, size/ratio, renderer);
}

int main(int argc, char* argv[])
{
     int n=4;
     double x=SCREEN_HEIGHT/2, y=SCREEN_WIDTH/2;
     double size = 300;

     SDL_Window* window;
     SDL_Renderer* renderer;
     initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
     // Your drawing code here
     // use SDL_RenderPresent(renderer) to show it

     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
     SDL_RenderClear(renderer);


     draw(n, x, y, size, renderer);

     waitUntilKeyPressed();
     quitSDL(window, renderer);
     return 0;
}

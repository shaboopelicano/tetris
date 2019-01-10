#include <SDL2/SDL.h>
#include <stdio.h>
#include <shared.h>

int main(int argc, char *argv[])
{
    SDL_Window *janela;
    SDL_Renderer *renderer;
    SDL_Event eventoContainer;
    int rodando = 1;

    IniciarJanela(&janela, &renderer);

    while (rodando)
    {
        SDL_RenderClear(renderer);
        SDL_Rect r = { 0 , 0 , 100 , 100 };
        SDL_RenderDrawRect(renderer,&r);
        SDL_RenderPresent(renderer);
        TratarEvento(eventoContainer, rodando);
        SDL_Delay(33);
    }

    LimparSair(&janela,&renderer);
    return 0;
}

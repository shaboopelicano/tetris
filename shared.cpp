#include <shared.h>

void IniciarJanela(SDL_Window **janela, SDL_Renderer **renderer)
{
    SDL_Init(SDL_INIT_VIDEO);

    *janela = SDL_CreateWindow(
        "TETRIS",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        LARGURA, ALTURA,
        0);

    *renderer = SDL_CreateRenderer(*janela, -1, 0);
    
}

void LimparSair(SDL_Window **janela,SDL_Renderer **renderer)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*janela);
    SDL_Quit();
}

void TratarEvento(SDL_Event e, int &rodando)
{
    if (SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
        case SDL_KEYDOWN:
            rodando = 0;
            break;
        case SDL_QUIT:
            rodando = 0;
            break;
        }
    }
}

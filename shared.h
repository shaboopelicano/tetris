#ifndef SHARED_H
#define SHARED_H

#include <SDL2/SDL.h>

#define LARGURA 800
#define ALTURA 600

typedef struct _Peca{
    int posX;
    int posY;
    SDL_Rect ret;
}Peca;

void IniciarJanela(SDL_Window **,SDL_Renderer **);
void TratarEvento(SDL_Event e,int &rodando);
void LimparSair(SDL_Window **,SDL_Renderer **);
Peca CriarPeca(uint8_t,uint8_t);

#endif
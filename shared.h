#ifndef SHARED_H
#define SHARED_H

#include <SDL2/SDL.h>

#define LARGURA 800
#define ALTURA 600
#define TRUE 1
#define FALSE 0
#define LARGURA_QUAD 100
#define ALTURA_QUAD 100

extern int GRAVIDADE;
extern int velX;

typedef int BOOL;
typedef struct _Peca{
    int posX;
    int posY;
    SDL_Rect ret;
}Peca;

void IniciarJanela(SDL_Window **,SDL_Renderer **);
void TratarEvento(SDL_Event e,int &rodando);
void LimparSair(SDL_Window **,SDL_Renderer **);
void AtualizarPosicaoPeca(Peca &p);
BOOL VerificarColisoes(Peca &p);
Peca CriarPeca();

#endif
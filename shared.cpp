#include <shared.h>

int GRAVIDADE = 1;
int velX = 0;


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
            switch(e.key.keysym.sym){
                case SDLK_ESCAPE:
                    rodando = 0;
                    break;
                case SDLK_LEFT:
                    velX = -1;
                    break;
                case SDLK_RIGHT:
                    velX = 1;
                    break;
            }
            break;
        case SDL_QUIT:
            rodando = 0;
            break;
        }
    }
}

void AtualizarPosicaoPeca(Peca &p){
    p.ret.y += GRAVIDADE;
    p.ret.x += velX;
}

BOOL VerificarColisoes(Peca &p){
    if(p.ret.x < 0){
        p.ret.x = 0;
        return FALSE;
    }
    else if(p.ret.x + LARGURA_QUAD > LARGURA){
        p.ret.x = LARGURA - LARGURA_QUAD;
        return FALSE;
    }
    else if(p.ret.y + ALTURA_QUAD > ALTURA){
        p.ret.y = ALTURA - ALTURA_QUAD;
    }
    else return TRUE;
}

Peca CriarPeca(){
    Peca p;
    p.posX = 0;
    p.posY = 0;
    SDL_Rect r = {0,0,100,100};
    p.ret = r;
    return p;
}

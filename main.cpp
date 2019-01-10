#include <shared.h>

int main(int argc, char *argv[])
{
    SDL_Window *janela;
    SDL_Renderer *renderer;
    SDL_Event eventoContainer;
    int rodando = 1;

    IniciarJanela(&janela, &renderer);
    Peca peca = CriarPeca();
    while (rodando)
    {
        // Limpar tela
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        
        // Posicionar Peça
        if(VerificarColisoes(peca))
            AtualizarPosicaoPeca(peca);

        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderFillRect(renderer, &peca.ret);

        // Apresentar, Eventos, Delay
        SDL_RenderPresent(renderer);
        TratarEvento(eventoContainer, rodando);
        SDL_Delay(1);
    }

    LimparSair(&janela, &renderer);
    return 0;
}

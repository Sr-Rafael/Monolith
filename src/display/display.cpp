/**
 * @file src/display/display.cpp
 * @author Rafael Neves (Hiperion)
 * @brief Implementação responsável por criar o display
 * @version 0.1
 * @date 2026-05-20
 * @copyright Copyright (c) 2026 Rafael Neves. Licença MIT.
 */

// ======================
// ====== Includes ======
// ======================
// [INFO]: Inclusão de arquivos
#include "display.hpp" // [INFO] Arquivo com o cabeçalho desta implementação

// [INFO]: Inclusão de bibliotecas padrão
#include <iostream> // [INFO]: Biblioteca para escrever erros e retornos no terminal (Para debug)
#include <SDL2/SDL.h> // [INFO]: Biblioteca do SDL2 que irá criar e desenhar na tela
#include <string> // [INFO]: Biblioteca para poder lidar com strings

// [INFO]: Declaração do namespace
namespace Monolith{
    // ======================================
    // ====== Declaração do construtor ======
    // ===== Render :: display ::display ====
    // ======================================

    /**
     * @brief Construtor da classe
     * @param 'l' Largura da janela a ser criada
     * @param 'a' Altura da janela a ser criada
     * @param 'titulo' Titulo da janela a ser criada
     */
    Monolith::display::display(int l, int a, std::string titulo) : 
            largura(l), // [INFO]: Inicializa a largura da janela
            altura(a), // [INFO]: Inicializa a altura da janela
            janela(nullptr), // [INFO]: Ponteiro para armazenar o endereço do local da janela
            renderizador(nullptr) // [INFO]: Ponteiro para desenhar na janela
            {
        // [INFO]: Verificação da inicialização do SDL
        if (SDL_Init(SDL_INIT_VIDEO)<0){
            // [INFO]: Em caso de falha executa o bloco if
            std::cerr << "\n=== ATENÇÂO ===\n[ERRO]: Falha ao inicializar o video!" << std::endl;
        };
        // [INFO]: Cria a janela para desenhar as coisas.
        janela = SDL_CreateWindow(titulo.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largura,altura,SDL_WINDOW_SHOWN);
        
        // [INFO]: Chama o renderizador do SDL
        renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    };

    // =====================================
    // ====== Declaração do Destrutor ======
    // === Render :: display :: ~dispaly ===
    // =====================================

    /**
     * @brief Destrutor da classe
     */
    Monolith::display::~display(){
        // [INFO]: Destroi o renderizador
        SDL_DestroyRenderer(renderizador);

        // [INFO]: Destroi a janela criada
        SDL_DestroyWindow(janela);

        // [INFO]: Fecha o SDL2
        SDL_Quit();
    }

    // ======================================================
    // ====== Declaração da função que desenha na tela ======
    // ============= Render :: display :: exibir ============
    // ======================================================

    /**
     * @brief Função para exibir algo na tela
     */
    void Monolith::display::exibir() {
        SDL_SetRenderDrawColor(renderizador,255,0,255,255);
        SDL_RenderClear(renderizador);
        SDL_RenderPresent(renderizador);
    }
}

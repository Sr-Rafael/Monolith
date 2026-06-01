/**
 * @file src/display/display.hpp
 * @author Rafael Neves (Hiperion)
 * @brief Declaração da implementação responsável por criar o display
 * @version 0.1
 * @date 2026-04-30
 * @copyright Copyright (c) 2026 Rafael Neves. Licença MIT.
 */

#pragma once // [INFO]: Flag para evitar inclusão multipla desse arquivo

// =========================
// ======= Inclusões =======
// =========================
// [INFO]: Inclusões de Bibliotecas
#include <SDL2/SDL.h> // [INFO]: Biblioteca responsável pelo display

// [INFO]: inclusão de bibliotecas padões
#include <string> // [INFO]: Biblioteca que possibilita o uso do tipo string

// [INFO]: Declaração do namespace
namespace Monolith {
    // [INFO]: Declaração da classe
    class display {
        // ==========================
        // ===== Itens privados =====
        // ==========================
        private:
            int largura; // [INFO]: Variável para definir a largura da janela
            int altura; // [INFO]: Variável para definir a altura da janela
            bool rodando; // [INFO]: Variável para poder marcar como rodando
            SDL_Window* janela;
            SDL_Renderer* renderizador;
            
        public:
            // ==========================
            // ===== Itens públicos =====
            // ==========================

            display(int l = 640, int a = 480, std::string titulo = "Hiperion"); // [INFO]: Construtor da classe
            ~display(); // [INFO]: Desconstrutor da classe

            void entrada(); // [INFO]: Função para processar a entrada do usuário
            void exibir(); // [INFO]: Função para exibir coisas no display

            bool estaRodando(); // [INFO]: Função para consutar o estado do programa
    };
}

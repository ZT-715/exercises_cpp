#include <iostream>
#include "FILO.hpp"

int main() {
    try {
        // Criação de um objeto FILO com tamanho inicial 5
        FILO filo1(5);
        
        // Adição de elementos ao FILO
        filo1.add(10).add(20).add(30).add(40).add(50);

        // Exibição dos elementos do FILO
        for (int i = 0; i < 5; ++i) {
            std::cout << "filo1[" << i << "] = " << filo1[i] << std::endl;
        }

        // Soma de todos os valores atualmente inseridos na FILO
        std::cout << "Soma dos valores na FILO: " << filo1.sum() << std::endl;


        // Remoção de um elemento do FILO
        std::cout << "Elemento removido: " << filo1.pop() << std::endl;

        // Exibição dos elementos do FILO após remoção
        for (int i = 0; i < 4; ++i) {
            std::cout << "filo1[" << i << "] = " << filo1[i] << std::endl;
        }

        // Soma de todos os valores atualmente inseridos na FILO
        std::cout << "Soma dos valores na FILO: " << filo1.sum() << std::endl;

        // Criação de uma cópia do FILO
        FILO filo2{filo1};

        // Modificação de um elemento na cópia
        filo2[2] = 100;
        std::cout << "Atribuição: filo2[2] = 100." << std::endl;

        // Exibição dos elementos do FILO original e da cópia
        std::cout << "Elementos do FILO original:" << std::endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << "filo1[" << i << "] = " << filo1[i] << std::endl;
        }

        std::cout << "Elementos da cópia do FILO:" << std::endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << "filo2[" << i << "] = " << filo2[i] << std::endl;
        }
        
        // Testando exceção ao acessar um índice inválido
        try {
            std::cout << "Acessando índice inválido: " << filo1[10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Exceção capturada: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }

    return 0;
}


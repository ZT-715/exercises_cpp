#include <iostream>
#include "FILO.hpp"

int main() {
    try {
        // Criação de um objeto FILO com tamanho inicial 5
        FILO filo1(5);
        
        // Adição de elementos ao FILO
        filo1.add(10).add(20).add(30).add(40).add(50);

        // Exibição dos elementos do FILO
        for (int i = 0; i < 5; i++) {
            std::cout << "filo1[" << i << "] = " << filo1[i] << std::endl;
        }

        // Soma de todos os valores atualmente inseridos na FILO
        std::cout << "Soma dos valores na FILO: " << filo1.sum() << std::endl;


        // Remoção de um elemento do FILO
        std::cout << "Elemento removido: " << filo1.pop() << std::endl;

        // Exibição dos elementos do FILO após remoção
        for (int i = 0; i < 4; i++) {
            std::cout << "filo1[" << i << "] = " << filo1[i] << std::endl;
        }

        // Soma de todos os valores atualmente inseridos na FILO
        std::cout << "Soma dos valores na FILO: " << filo1.sum() << std::endl;

        // Criação de uma cópia do FILO
        FILO filo2{filo1};

        // Modificação de um elemento na cópia
        filo2[2] = 100;
        std::cout << "Atribuição: filo2[2] = 100." << std::endl;

        // Criação de uma cópia do FILO
        FILO filo3 = filo2;

        // Modificação de um elemento na cópia
        filo3[3] = 100;
        std::cout << "Atribuição: filo3[3] = 100." << std::endl;

        // Adição de valores além da memória alocada no construtor
        filo3.add(100).add(50);
        std::cout << "Adição: filo3.add(100).add(50)." << std::endl;

        // Exibição dos elementos do FILO original e das cópias
        std::cout << "Elementos do FILO original:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "filo1[" << i << "] = " << filo1[i] << std::endl;
        }

        std::cout << "Elementos da cópia do FILO:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "filo2[" << i << "] = " << filo2[i] << std::endl;
        }
        
        std::cout << "Elementos da 2a cópia do FILO:" << std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << "filo3[" << i << "] = " << filo3[i] << std::endl;
        }

        // Testando ordem de remoção de elementos
        std::cout << "Remoção de elementos da FILO3: " << std::endl;
        for (int i = 0; i < 6; i++){
            std::cout << i << ". filo3.pop() = " << filo3.pop() << std::endl;
        };
        
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


/*
 * Crie uma classe que represente uma estrutura de uma FILO, de valores tipo
 * int. A classe deve ter um construtor que indique a quantidade de elementos
 * inicial desejada (podendo ser zero). A FILO deve permitir
 * a alocação/liberação dinâmica de memória.  A classe deve apresentar métodos
 * que permitam:
 * V 1) construtor default, construtor por cópia (deep) e construtor por
 *   atribuição (deep)
 * V 2) adicionar e remover um elemento da FILO (um método para cada - caso
 *   o tamanho anterior da FILO seja ultrapassado, será necessário alocar mais
 *   memória; no caso da remoção, só libere memória e faça a readequação da área
 *   anteriormente alocada caso existam mais de 50% de elementos livres.
 * 3) consultar o valor de um elemento em uma posição válida, arbitrária, da
 *   FILO, via operador sobrescrito
 * 4) alterar o valor de um elemento em uma posição válida, arbitrária, da FILO,
 *    via operador sobrescrito
 * V 5) retornar a soma de todos os valores atualmente inseridos na FILO.
 * 6) operador sobrescrito que permita a conversão do valor de uma posição da
 *   FILO para uma std::string
 * 7) ex:ceções adequadas que indiquem erros no uso da classe
 * 8) Uma função main() que permita exemplificar a operação da classe. 
*/

#ifndef FILO_HPP
#define FILO_HPP


#include<stdexcept>

class FILO {
    private:
        int size, top;
        int* head;

    public:
        FILO(int size); 
        FILO(const FILO& copy);
        FILO& operator=(const FILO& copy);         

        FILO& add(int a);                 
        int pop(); 

//      TODO: 
//      sobreescrever  [] para atribuição e leitura

        int sum();
        ~FILO();
};

#endif

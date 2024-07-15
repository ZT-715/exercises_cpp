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

#include<stdexcept>
#include"FILO.hpp"

FILO::FILO(int size): size{size} {
    if(size < 0) {
        throw std::invalid_argument("FILO size must not be negative.");
    } 
    head = new int[size];         
}

FILO::FILO(const FILO& copy): size{copy.size}, top{copy.top} {
   head = new int[copy.size];

    for(int i; i < top; i++){
        head[i] = copy.head[i];
    }

}

FILO& FILO::operator=(const FILO& copy) {
    delete [] head;
    
    top = copy.top;
    size = copy.size;
    head = new int[copy.size];

    for(int i; i < top; i++){
        head[i] = copy.head[i];
    }
    return *this;
}

FILO& FILO::add(int a) {
    if(top + 1 > size){
        int new_size = size + 1 + size/2;
        int* new_head = new int[new_size];

        for (int i = 0; i < top; i++)
            new_head[i] = head[i];

        delete [] head;

        head = new_head;
        size = new_size;
    }

    head[top++] = a;
    return *this;
}
        
int FILO::pop() {
    int a = head[top];

    if (size/2 > top) {
        int new_size = size/2;
        int* new_head = new int[new_size];

        for (int i = 0; i < top; i++)
            new_head[i] = head[i];

        delete [] head;

        head = new_head;
        size = new_size;
    }

    return a;
}

//      TODO: 
//      sobreescrever  [] para atribuição e leitura

int FILO::sum() {
    int s = 0;

    for(int i = 0; i < top; i++) {
        s += head[i];
    }
    
    return s;
} 

FILO::~FILO() {
    delete [] head;
}

/*
 * TAREFA B Crie uma classe que represente uma lista encadeada de valores
 * inteiros, ordenada em sentido crescente. A classe deve usar uma estrutura
 * guardando o valor de um elemento, bem como um ponteiro para o elemento
 * anterior e posterior da lista.  Deve ter no mínimo um campo privados,
 * indicando um ponteiro para o primeiro elemento da lista. Deve ter ainda
 * uma indicação de quantos elementos a lista possui. 
 * A classe deve apresentar um construtor default que inicialize todas as
 * operações  e campos da lista.
 *
 * A classe deve apresentar os seguintes métodos:
 * 1) um método que permita a inserção de um novo elemento na lista -- nesse
 *   caso, a inserção deve ser feita mantendo a ordem numérica.
 * 2) um método que retorne a quantidade de elementos da lista
 * 3) um método para retornar o valor do n-ésimo elemento da lista, 
 *   a partir de um argumento indicando o índice do elemento (caso não 
 *   exista o elemento, deve ser retornado um código de erro adequado)
 * 4) um método para verificar se um dado valor está ou não presente na lista
 * 5) um método para remover um certo elemento da lista, a partir do valor
 *   indicado. 
*/

// USAR MÚLTIPLOS ARQUIVOS
// NAO É NECESSÁRIO INICIALIZAÇÃO DA LISTA JÁ COM SÉRIE DE VALORES
//
#include <stdexcept>

struct element {
    int value;
    struct element* nx;
    struct element* pr;
};

class List {
    element* root;
    int size;

public:
    List();
    int len();
    int get(int position); // position < size
    bool insert(int value);
    bool isin(int value);
    bool remove(int value);
    ~List();
};

List::List(){
    root = nullptr;
    size = 0;
}

bool List::insert(int value) {
    element* cursor = root;
    element* tmp = new element;

    tmp->value = value;
    tmp->nx = nullptr;
    tmp->pr = nullptr;

    size++;

    if (!root) {
        root = tmp;
        return true;
    }

    if (root->value > tmp->value) {
        tmp->nx = cursor;
        root->pr = tmp;
        root = tmp;

        return true;
    }

    while (true) {
        if (!cursor->nx) {
            break;
        }
        if (cursor->nx->value >= tmp->value) {
            break;
        }
        cursor = cursor->nx;
    }

    if (cursor->nx) {
        tmp->nx = cursor->nx;
        tmp->nx->pr = tmp;
    }
    cursor->nx = tmp;

    tmp->pr = cursor;

    return true;
}

int List::len() {
    return size;
}

int List::get(int position) {
    element* cursor = root;

    if (position >= size) {
        throw std::out_of_range("List access out of range");
    }

    for (int i = 0; i < position; i++) {
        cursor = cursor->nx;
    }

    return cursor->value;
}

bool List::isin(int value) {
    element* cursor = root;

    for (int i = 0; i < size; i++) {
        if (cursor->value == value) return true;
        cursor = cursor->nx;
    }
    return false;
}

bool List::remove(int value) {
    if (!isin(value)) return false;

    element* tmp = nullptr;
    element* cursor = root;

    for (int i = 0; i < size; i++) {
        if (cursor->value == value) break;
        cursor = cursor->nx;
    }

    tmp = cursor;

    cursor->pr = tmp->nx;
    cursor->nx = tmp->pr;

    if (root == tmp) root = tmp->nx;

    size--;

    delete tmp;
    return true;
}

List::~List() {
    while (size > 0) remove(get(0));
}


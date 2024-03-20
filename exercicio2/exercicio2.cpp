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

#include<stdexcept>


struct element {
    int value;
    struct element* nx;
    struct element* pr;
}

class List {
    element* node;
    int size;

public:
    explicit List();
    int len();
    int get(int position); // position < size
    bool insert(int value);
    bool isin(int value);
    bool remove(int value);
    ~List();
}

List::List(){
    node {nullptr};
    size {0};
}
bool List::insert(int value){
    element* cursor {node};
    element* new_node {new element};
    
    new_node->value {value};
    new_node->nx {nullptr};
    new_node->pr {nullptr};

    size++;

    if(!node){
        node {new_node};
        return true;
    }
    
    if(node->value > new_node->values){
        new_node->nx {cursor};
        node->pr {new_node};
        node {new_node};

        return true;
    }

    while(true){
        if(!cursor->nx){
            break;
        }
        if(cursor->nx->value >= new_node->value){
            break;
        }
        cursor {cursor->nx};
    }
    
    if(cursor->nx){
        new_node->nx {cursor->nx};
        new_node->nx->pr {new_node};
    }
    cursor->nx {new_node};

    new_node->pr {cursor};
  
    return true;
}

int size(){
    return size;
}
int get(int position){
   element* cursor {node};
   
   if(postition > size) throw std::out_of_range("List access out of range");

   for(int i {0}; i < position; i++){
        cursor {cursor->nx};
   }

   return cursor->value;
}

bool isin(int value){
    element* cursor {node};

    for(int i {0}; i < size; i++){
        if(cursor->value == value) return true;
        cursor {cursor->nx};
    }
    return false;
}

bool remove(int value){
    if(!this->isin(value)) return false;
   
    element* tmp {nullptr};
    element* cursor {node};

    for(int i {0}; i < size; i++){
        if(cursor->value == value) break;
        cursor {cursor->nx};
    }   

    tmp {cursor};

    cursor->pr {tmp->nx};
    cursor->nx {tmp->pr};

    if(node==tmp) node {tmp->nx};

    size--;

    delete tmp;
    return true;
}

List::~List(){
    while(size > 0) remove(get(0));
}

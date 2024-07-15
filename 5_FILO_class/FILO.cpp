#include"FILO.hpp"

FILO::FILO(int size): size{size}, top{0} {
    if(size < 0) {
        throw std::invalid_argument("FILO size must not be negative.");
    } 
    head = new int[size];         
}

FILO::FILO(const FILO& copy): size{copy.size}, top{copy.top} {
    head = new int[copy.size];

    for(int i = 0; i < top; i++){
        head[i] = copy.head[i];
    }
}

FILO& FILO::operator=(const FILO& copy) {
    // Verifica de auto-atribuição
    if (this == &copy) {
        return *this;
    }

    int* new_head = new int[copy.size];

    for(int i = 0; i < copy.top; i++) {
        new_head[i] = copy.head[i];
    }

    delete[] head;

    head = new_head;
    size = copy.size;
    top = copy.top;

    return *this;
}

int& FILO::operator[](int index){
    if(index < 0 || index > top)
        throw std::out_of_range("Index outside of range."); 
    return head[index];
}

std::string FILO::operator[](int index) const {
    if(index < 0 || index > top)
        throw std::out_of_range("Index outside of range."); 
    return std::to_string(head[index]);
}

FILO& FILO::add(int a) {
    if(top + 1 == size){
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
    int a = head[--top];

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

int FILO::sum() const {
    int s = 0;

    for(int i = 0; i < top; i++) {
        s += head[i];
    }
    
    return s;
} 

FILO::~FILO() {
    delete [] head;
}

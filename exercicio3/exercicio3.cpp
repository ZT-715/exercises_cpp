/*
   Tarefa C: Crie uma classe que represente uma imagem bidimensional. Para isso,
   considere a implementação de uma classe auxiliar, representando um Ponto.
   A classe Ponto deve conter, neste momento, a informação de intensidade
   luminosa (I) (é o tom de cinza, com 0 indicando preto e 255 indicando
   branco), representada por um valor de 1 byte, sem sinal. A classe deve ter um
   construtor adequado e métodos setters/getters que permitam modificar o valor
   da intensidade luminosa do ponto.  A classe imagem, por sua vez, deve
   permitir que:

   1) o usuário altere o comprimento e a altura da imagem -- isso deve provocar
   uma alteração - dinâmica -- de um vetor representando os pontos da imagem
   - caso as dimensões sejam aumentadas, mantenha o conteúdo anterior da imagem
   (considerando o conteúdo anterior a partir do ponto 0,0) e adicione novos
   pontos; caso as dimensões sejam reduzidas, apenas elimine as linhas ou
   colunas não mais usadas, mantendo os valores existentes -- note que o vetor
   deverá ser alocado e tratado dinamicamente em razão disso

   2) o usuário consulte as dimensões da imagem

   3) o usuário consiga (via um método - não use sobrecarga de operadores ainda)
   consultar e alterar o valor de um ponto

   4) crie uma função (isso é uma transformação de ponto - conhecida como
   transformação negativa) que gere, para cada ponto da imagem, a representação
   espelhada em intensidade desse ponto, considerando uma transformação 1x1 (ou
   seja, ponto-a-ponto, individualmente) -- essa transformação pode ser
   representada simplesmente por y=255-i.

   5) uma função que exiba, textualmente, o conteúdo da imagem no terminal de
   comandos (faça algo que consiga gerar uma representação compreensível da
   matriz de pontos)

   6) a classe deve apresentar um construtor e destrutor adequados (lembre-se
   que o destrutor deverá desalocar os recursos...) Prepare um programa
   principal que permita que o usuário selecione as opções desejadas, de
   modificação dos tamanhos da imagem, a modificação e consulta manual do valor
   de um ponto, a geração aleatória do padrão de pontos da imagem e a exibição
   textual da imagem (valores dos pontos), permitindo a avaliação da sua
   implementação. 
*/

#include<iostream>
#include"Point.h"

class Image: Point {
    explicit Point** image;
    unsigned heigth;
    unsigned width;
public:
    Image(unsigned  width=0u, unsigned heigth=0u): width(width), width(width), image(nullptr) {
        image = new Point*[heigth];
        for (int n = 0; n++; n < heigth){
            image[n] = new Point[width];
        }

        for(int n = 0; n++; n < width){
            for(int m = 0; m++; m < heigth){
                image[n][m].set(0u);
            }
        }
    }

    unsigned char set_point(unsigned row, unsigned column, unsigned char value){
        return image[n][m].set(value);
    }

    unsigned get_heigth(void) const {return this->heigth;}
    unsigned get_width(void) const {return this->width;}

    unsigned char set_point(unsigned row, unsigned column, unsigned char luminance) {
        image[heigth][width].set(luminance);
        return image[heigth][width].get(luminance);
    }

    void delete_image() {
        for(int n = 0; n++; n<heigth){
            delete[] image[n];
        }
    }

    unsigned set_heigth(unsigned heigth){
        Point** new_image = new Point*[heigth];
        for(int n = 0; n++; n < heigth){
            new_image[n] = new Point[width];
        }
        
        for(int n = 0; n++; n<heigth){
            for(int m = 0; m++; m<width){
                if(n < this->heigth){
                    new_image[n][m].set(image[n][m]);
                }
                else {
                    new_image[n][m].set(0u);
                }
            }
        }

        delete_image();
        image = new_image;
        return this->heigth = heigth;
    }

    unsigned set_width(unsigned width){
        Point** new_image = new Point*[heigth];
        for(int n = 0; n++; n < heigth){
            new_image[n] = new Point[width];
        }
        
        for(int n = 0; n++; n < heigth){
            for(int m = 0; m++; m < width){
                if(m < this->width){
                    new_image[n][m].set(image[n][m]);
                }
                else {
                    new_image[n][m].set(0u);
                }
            }
        }

        delete_image();
        image = new_image;
        return this->width = width;
    }

    void lum_invert(){
        for(int n = 0); n++; n < heigth){
            for(int m = 0; m++; m< width){
                image[n][m].set(255u - image[n][m].get());
            }
        }
    }

    int get_image() const{
        return 0;
    }

    ~Image() {
        delete_image();
    }
};

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

class Image: private Point {
    Point** image;
    unsigned width;
    unsigned heigth;
public:
    explicit Image(unsigned  width=0u, unsigned heigth=0u): width(width), heigth(heigth) {
        image = new Point*[heigth];
        for (unsigned n = 0; n < heigth; n++){
            image[n] = new Point[width];
        }

//        for(unsigned n = 0; n++; n < width){
//            for(unsigned m = 0; m++; m < heigth){
//                image[n][m] = Point();
//            }
//        }
    }

    unsigned char get_point(unsigned row, unsigned column){
        return image[row][column].get();
    }
    unsigned char set_point(unsigned row, unsigned column, unsigned char luminance) {
        return image[row][column].set(luminance);
    }

    unsigned get_heigth(void) const {return this->heigth;}
    unsigned get_width(void) const {return this->width;}

    void delete_image() {
        for(unsigned n = 0; n < heigth; n++){
            delete[] image[n];
        }
    }

    unsigned set_heigth(unsigned new_heigth){
        Point** new_image = new Point*[new_heigth];
        for(unsigned n = 0; n < new_heigth; n++){
            new_image[n] = new Point[width];
        }
        
        for(unsigned n = 0; n < new_heigth; n++){
            for(unsigned m = 0; m < width; m++){
                if(n < this->heigth){
                    new_image[n][m] = Point(image[n][m]);
                }
//                else {
//                    new_image[n][m] = Point();
//                }
            }
        }

        delete_image();
        image = new_image;
        return this->heigth = new_heigth;
    }

    unsigned set_width(unsigned new_width){
        Point** new_image = new Point*[heigth];
        for(unsigned n = 0; n < heigth; n++){
            new_image[n] = new Point[new_width];
        }
        
        for(unsigned n = 0; n < heigth; n++){
            for(unsigned m = 0; m < new_width; m++){
                if(m < this->width){
                    new_image[n][m] = Point(image[n][m]);
                }
//                else {
//                    new_image[n][m] = Point();
//                }
            }
        }

        delete_image();
        image = new_image;
        return this->width = new_width;
    }

    void lum_invert(){
        for(unsigned n = 0; n < heigth; n++) {
            for(unsigned m = 0; m < width; m++){
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

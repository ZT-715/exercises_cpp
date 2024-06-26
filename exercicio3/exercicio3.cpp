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
#include"Image.h"

using namespace std;

int main(void){
    int choice {0};
    Image image{40u,10u};
    
    unsigned column, row;
    unsigned luminance;
    unsigned new_width, new_height;

    cout << "Example image created:" << endl;

    while(choice != 9){

        cout << endl << image.get_image() << endl;

        cout  << "\e[38;2;" << 180 << ";" << 180 << ";" << 180 << "m";
        cout << "#####Menu######" << endl;
        cout << "1 - Get height" << endl;
        cout << "2 - Get width" << endl;
        cout << "3 - Set height" << endl;
        cout << "4 - Get point luminance" << endl;
        cout << "5 - Set width" << endl;
        cout << "6 - Set point luminance" << endl;
        cout << "7 - Set random" << endl;
        cout << "8 - Lum invert" << endl;
        cout << "9 - Exit" << endl;
        cout << "###############"  << endl << endl;

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Height: " << image.get_height() << endl;
                break;
            case 2:
                cout << "Width: " << image.get_width() << endl;
                break;
            case 3: 
                cout << "Enter new height: ";
                cin >> new_height;
                image.set_height(new_height);
                break;
            case 4: 
                cout << "Point row: "; 
                cin >> row;
                cout << "Point column: ";
                cin >> column;
                cout << "Point luminance is: " << (unsigned)image.get_point(row, column) << endl;
                break;
            case 5: {
                cout << "Enter new width: ";
                cin >> new_width;
                image.set_width(new_width);
                break;
            }
            case 6: 
                cout << "Point row: "; 
                cin >> row;
                cout << "Point column: ";
                cin >> column;
                cout << "New luminance value (0 to 255): ";
                cin >> luminance;
                image.set_point(row, column, (unsigned char)luminance);
                break;
            case 7:
                image.set_random();
                break;
            case 8:
                image.lum_invert();
                break;
            default:
                break;
        }
    }   
    return 0;
}

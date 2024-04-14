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

#include<string>
#include<iostream>
#include"Image.h"

int main(void){
    Image img(40u, 10u);

    img.set_random();

    std::cout << img.get_image() << std::endl;

    return 0;
}

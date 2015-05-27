#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TOKEN_T{OperadorNegacao, OperadorConjuncao, OperadorDisjuncao, OperadorImplicacao, OperadorEquivalencia,
AbreParenteses, FechaParenteses,
Virgula, Ponto_e_Virgula, Atribuicao,
Palavra_Reservada_If, Palavra_Reservada_Else, Palavra_Reservada_Read, Palavra_Reservada_Print,
Identificador,
Valor_Logico_Verdadeiro, Valor_Logico_Falso,
AbreChaves, FechaChaves};

//Variaveis Globais
char Matriz[50][80];
int Linha_Atual;
int Coluna_Atual;

//Protótipos
void Sintatico();
int le_token();



int main(){

    FILE *arq;
    int linha = 0, i , j;
    arq = fopen("Entrada.txt", "r");
    if(!arq){
        printf("Erro!!!");
        return 0;
    }
    //inicialização da matriz
    for(i=0;i<50;i++){
        for(j=0;j<80;j++){
         Matriz[i][j] = '\0';
        }
    }
    ///inicialização da linha e coluna atual
    Linha_Atual = 0;
    Coluna_Atual = 0;

    //leitura do arquivo
    while(feof(arq) == 0){
        fgets(Matriz[linha], 99, arq);
        linha++;
    }

/*
    linha = 0;

    for(i=0;i<50;i++){
        for(j=0;j<80;j++){
            printf("%c", Matriz[i][j]);
            linha++;
        }
        printf("\n");
    }
*/

    Sintatico();
    return 0;
}


void Sintatico(){
    int d;
    d = le_token();
    printf("%d", d);

}


int le_token(){
    char aux_vet[21];
    int i;
    char aux;

    for(i=0;i<21;i++){
        aux_vet[i] = '\0';
    }

    i = 0;

    aux = Matriz[Linha_Atual][Coluna_Atual];
    /*while(aux == ' ' || aux == '\n' || aux == '\b' || aux == '\t'){
        Linha_Atual++;
        aux = Matriz[Linha_Atual][Coluna_Atual];
    }*/

    while(aux != '\t' && aux != ' ' && aux != '\b' && aux != '\n'){
        aux_vet[i] = aux;
        i++;
        Coluna_Atual++;
        aux = Matriz[Linha_Atual][Coluna_Atual];
    }

    if(strcmp("(", aux_vet) == 0){
        return AbreParenteses;
    }

    else if(strcmp(")", aux_vet) == 0){
        return FechaParenteses;
    }

    else if(strcmp("<->", aux_vet) == 0){
        return OperadorEquivalencia;
    }

    else if(strcmp("->", aux_vet) == 0){
        return OperadorImplicacao;
    }

    else if(strcmp("^", aux_vet) == 0){
        return OperadorConjuncao;
    }

    else if(strcmp("v", aux_vet) == 0){
        return OperadorDisjuncao;
    }

    else if(strcmp("'", aux_vet) == 0){
        return OperadorNegacao;
    }

    else if(strcmp("if", aux_vet) == 0){
        return Palavra_Reservada_If;
    }

    else if(strcmp("else", aux_vet) == 0){
        return Palavra_Reservada_Else;
    }

    else if(strcmp("Read", aux_vet) == 0){
        return Palavra_Reservada_Read;
    }

    else if(strcmp("Print", aux_vet) == 0){
        return Palavra_Reservada_Print;
    }

    else if(strcmp(";", aux_vet) == 0){
        return Ponto_e_Virgula;
    }

    else if(strcmp(",", aux_vet) == 0){
        return Virgula;
    }

    else if(strcmp("=:=", aux_vet) == 0){
        return Atribuicao;
    }

    else if(strcmp("{", aux_vet) == 0){
        return AbreChaves;
    }

    else if(strcmp("}", aux_vet) == 0){
        return FechaChaves;
    }

    else if(strcmp("1", aux_vet) == 0 || strcmp("V", aux_vet) == 0 || strcmp("true", aux_vet) == 0){
        return Valor_Logico_Verdadeiro;
    }

    else if(strcmp("0", aux_vet) == 0 || strcmp("F", aux_vet) == 0 || strcmp("false", aux_vet) == 0){
        return Valor_Logico_Falso;
    }

    else if(aux_vet[0] == '_' || (aux_vet[0] >= 'a' && aux_vet[0] <= 'z') || (aux_vet[0] >= 'A' && aux_vet[0] <= 'Z')){
        return Identificador;
    }
    else{
        return -1;
    }
}



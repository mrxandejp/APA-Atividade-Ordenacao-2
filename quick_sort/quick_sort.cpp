#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int particao(int *ord, int comeco, int fim){
    int pivo = ord[fim];
    int aux;
    int i = comeco - 1;

    for(int j = comeco; j <= fim-1; j++){
        if(ord[j] < pivo){
            i++;
            aux = ord[i];
            ord[i] = ord[j];
            ord[j] = aux;
        }
    }
    if(ord[fim] < ord[i+1]){
        aux = ord[i+1];
        ord[i+1] = ord[fim];
        ord[fim] = aux;
    }
    return (i+1);
}

void quick_sort(int *ord, int comeco, int fim){

    if (comeco < fim){
        int aux = particao(ord, comeco, fim);
        quick_sort(ord, comeco, aux-1);
        quick_sort(ord, aux+1, fim);
    }
}


void print(int *num, int tamanho ){
      for (int i = 0; i < tamanho; i++)
      {
           cout << num[i] << "\t";
      }
      cout << endl;
 }

int main(){
    int ord[100000];
    string file;
    cout << "Digite o nome do arquivo a ser ordenado: ";
    cin >> file;
    ifstream in(file);
    char numero[10];
    int tamanho = 0;
    while(!in.eof()){

        in >> numero;
        ord[tamanho] = atoi(numero);
        tamanho++;
    }

    quick_sort(ord, 0, tamanho-1);

    print(ord, tamanho);

}


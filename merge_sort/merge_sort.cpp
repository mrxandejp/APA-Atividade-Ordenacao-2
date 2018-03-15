#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void intercalar(int *ord, int inicio, int meio, int fim){
    int ini, ini1, ini2, i;
    ini = 0;
    ini1 = inicio;
    ini2 = meio+1;
    i = fim - inicio +1;

    int aux[i];

    while((ini1 <= meio) && (ini2 <= fim)){
        if(ord[ini1] <= ord[ini2]){
            aux[ini] = ord[ini1];
            ini1++;
        }
        else{
            aux[ini] = ord[ini2];
            ini2++;
        }
        ini++;
    }

    while(ini1 <= meio){
        aux[ini] = ord[ini1];
        ini1++;
        ini++;
    }

    while(ini2 <= fim){
        aux[ini] = ord[ini2];
        ini2++;
        ini++;
    }

    for(ini=inicio; ini<=fim; ini++){
        ord[ini] = aux[ini-inicio];
    }
}

void merge_sort(int *ord, int inicio, int fim){
    //int meio;
    if (inicio < fim) {
        int meio = (fim+inicio)/2;
        merge_sort(ord, inicio, meio);
        merge_sort(ord, meio+1, fim);
        intercalar(ord, inicio, meio, fim);
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
    int fim = 0;
    while(!in.eof()){

        in >> numero;
        ord[fim] = atoi(numero);
        fim++;
    }

    merge_sort(ord, 0, fim-1);

    print(ord, fim);

}


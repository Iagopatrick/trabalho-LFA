#include <bits/stdc++.h>

using namespace std;


int main(){
    FILE *arq;
    char var[100];
    int saida, i = 0;
    string entrada;

    arq = fopen("arquivoTeste.txt", "r");
    
    do{
        fgets(var, 100, arq);
        entrada = var;
        cout << entrada.size() - 1 << "\n";

    }while(!feof(arq));
     




    return 0;
}
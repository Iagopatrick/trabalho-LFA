#include <bits/stdc++.h>

using namespace std;


/*      ANOTAÇÕES
Talvez seja necessário analisar como uma string, pois a entrada 123456 só verifica se o primeiro elemento, '1', é um número.
exemplo de entrada e saida:
[2*(4+3)]
ABRE COLCHETE
NUM
OP
ABRE ASPAS
NUM
OP
NUM
FECHA ASPAS
FECHA COLCHETE

*/ 



char ehNumero(char entrada){
    // Função que verifica que a entrada é um token do tipo numero. A função faz isso usando o intervalo dos número em ASCII.

    int cont = 0;
    while(int(entrada) >= 48 && int(entrada) <= 57){
        cont++;
        cin >> entrada;
    }
    if(cont > 0){
        cout << "<num>\n";
    }

    return entrada;
}

char ehVariavel(char entrada){
    // Função que verifica que a entrada é um token do tipo variavel. Só para quando o próximo é uma opreção ou um externo.
    // ATENÇÃO: falta verificar se é um externo

    int cont = 0;
    while(entrada != '+' && entrada != '-' && entrada != '/' && entrada != '*'){
        cont++;
        cin >> entrada;
    }
    if(cont > 0){
        cout << "<variavel>\n";
    }
    return entrada;
}

void ehOp(char entrada){
    // Função que verifica que a entrada é um token do tipo operação

    if(entrada == '+' || entrada == '-' || entrada == '/' || entrada == '*'){
        cout << "<OP>\n";
    }

}

void externos(char entrada){
    // CHAVES COLCHETES PARENTES
    // Essa função irá verificar se o caracter é [] {} () e associar aos tokens. Faço isso verificando os intervalos,
    // caso esteja no intervalo desses 'externos', então eu entro dentro da possibilidade de ser um token valido. Caso seja invalido,
    // o programa para e aparece uma mensagem de erro.


    if (int(entrada) >= 123 && int(entrada) <= 125){ //está no intervalo das chaves
        if(entrada == '['){
            cout << "<ABRE-CHAVES>\n";
        }else if(entrada == ']'){
            cout << "<FECHA-CHAVES>\n";
        }else{
            perror("Erro, caracter inválido!");
        }
    }
    else if (int(entrada) >= 91 && int(entrada) <= 93){ //está no intervalo dos colchetes
        if(entrada == '['){
            cout << "<ABRE-COLCHETES>\n";
        }else if(entrada == ']'){
            cout << "<FECHA-COLCHETES>\n";
        }else{
            perror("Erro, caracter inválido!");
        }
    }else if(int(entrada) >= 40 && int(entrada) <= 41){
        if(entrada == '('){
            cout << "<ABRE-PARENTESES>\n";
        }else if(entrada == ')'){
            cout << "<FECHA-PARENTESES>\n";
        }else{
            perror("Erro, caracter inválido!");
        }
    }



}



int main(){
    char entrada;
    char saida;
    bool flag = true;
    // tokens
    // char num[10] = {0,1,2,3,4,5,6,7,8,9};
    
    do{
        cin >> entrada;
        cout << int(entrada) << " " << entrada;
        if((entrada >= 32 && entrada<= 39) || (entrada >= 58 && entrada <= 64) || entrada == 44 ||entrada == 46){ //imtervalo de símbolos não aceitos na linguagem
            flag = false;
            cout << "entrada invalida!\n";
            break;
        }else{
            if(int(entrada) >= 48 && int(entrada) <= 57){
                saida = ehNumero(entrada);
            }else{
                saida = ehVariavel(entrada);
            }
            ehOp(saida);
            externos(saida);
        }
        

    }while(entrada != EOF);




    return 0;
}
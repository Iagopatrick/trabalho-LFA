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



bool ehNumero(char entrada){
    // Função que verifica que a entrada é um token do tipo numero. A função faz isso usando o intervalo dos número em ASCII.
    if(int(entrada) >= 48 && int(entrada) <= 57){
      return true;
    }
    return false;
}

bool ehVariavel(char entrada){
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
    if (int(entrada) >= 91 && int(entrada) <= 93){ //está no intervalo dos colchetes

    }
}


void error(char entrada);


int main(){
  // 250 + 123
    string entrada;
    char saida;
    bool flag = true;

    
    do{
      //talvez seja melhor usar iterator para acessar a string
        cin >> entrada;
        cout << int(entrada) << " " << entrada;
        for(int i = 0; i < entrada.size(); i++){
          if((entrada[i] >= 32 && entrada[i]<= 41) || (entrada[i] >= 58 && entrada[i] <= 64)){ //imtervalo de símbolos não aceitos na linguagem
            flag = false;
            cout << "entrada invalida!\n";
          }else{
              if(int(entrada[i]) >= 48 && int(entrada[i]) <= 57){
                  saida = ehNumero(entrada[i]);
                  number = true;
                  break;
              }else{ 
                  saida = ehVariavel(entrada[i]);
              }
            ehOp(entrada[i]);
            externos(entrada[i]        }
        }
        
        

    }while(entrada != EOF);




    return 0;
}

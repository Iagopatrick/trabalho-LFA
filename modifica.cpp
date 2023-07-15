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



int ehNumero(string entrada, int i){
    // Função que verifica que a entrada é um token do tipo numero. A função faz isso usando o intervalo dos número em ASCII.
    
    while(int(entrada[i]) >= 48 && int(entrada[i]) <= 57){
        i++;
    }
    return i;
}

int ehVariavel(string entrada, int i){
    // Função que verifica que a entrada é um token do tipo variavel. Só para quando o próximo é uma opreção ou um externo.
    // ATENÇÃO: falta verificar se é um externo

    
    while((int(entrada[i]) >= 48 && int(entrada[i]) <= 57) || (int(entrada[i]) >= 65 && int(entrada[i]) <= 90) || (int(entrada[i]) >= 97 && int(entrada[i]) <= 122)){
        i++;
    }
   
    return i;
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
        if(entrada == '{'){
            cout << "<ABRE-CHAVE>\n";
        }else if(entrada == '}'){
            cout << "<FECHA-CHAVE>\n";
        }else{
            perror("Erro, caracter inválido!");
        }
    }
    else if (int(entrada) >= 91 && int(entrada) <= 93){ //está no intervalo dos colchetes
        if(entrada == '['){
            cout << "<ABRE-COLCHETE>\n";
        }else if(entrada == ']'){
            cout << "<FECHA-COLCHETE>\n";
        }else{
            perror("Erro, caracter inválido!");
        }
    }else{
        if(entrada == '('){
            cout << "<ABRE-PARENTESE>\n";
        }else if(entrada == ')'){
            cout << "<FECHA-PARENTESE>\n";
        }else{
            perror("Erro, caracter inválido!");
        }
    }
}


bool verificaExternos(char entrada){
    char externos[6] = {'(', ')', '[', ']', '{', '}'};
    bool flag = false;
    for(int i = 0; i < 6; i++){
        if(externos[i] == entrada){
            flag = true;
            break;
        }
    }
    return flag;
}

int main(){
  
    char var[100];
    int saida, i = 0;
    string entrada;
    FILE *arq;
    
    
    arq = fopen("arquivoTeste.txt", "r");

   
    do{
        fgets(var, 100, arq);
     

        entrada = var;
        
        cout << entrada;
        for(i = 0; i < entrada.size(); i++){
            
            // cout << "elemento verificado: " << entrada[i] << "valor de i: " << i << "\n";
            if(int(entrada[i]) >= 48 && int(entrada[i]) <= 57){
                saida = ehNumero(entrada, i);
                i = saida - 1;
                cout << "<NUM>\n";
                continue;
            }else if((int(entrada[i]) >= 65 && int(entrada[i]) <= 90) || (int(entrada[i]) >= 97 && int(entrada[i]) <= 122)){ 
                saida = ehVariavel(entrada, i);
                i = saida - 1;
                cout << "<VAR>\n";
                continue;
            }else if(entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '/' || entrada[i] == '*'){
                cout << "<OP>\n";
            }else if(verificaExternos(entrada[i])){
                externos(entrada[i]);
            }else{
                if(entrada[i] == '\n'){
                    break;
                }else if(entrada[i]== ' '){
                    continue;
                }
                cout << "entrada invalida!\n";
                cout << "carcateres esperados: 1234567890abcdefghijklmnopqrstuvwxyz+-*/(){}[] caracter recebido: " << entrada[i] << "\n";
                break;
            }
            
        }
    }while(!feof(arq));

    return 0;
}

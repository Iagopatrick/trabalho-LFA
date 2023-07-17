#include <bits/stdc++.h> //include de todas as bibliotecas padrão, usado na competição de maratona para velocidade e eficiência

using namespace std;

int ehNumero(string entrada, int i){
    /*
    Função que verifica que a entrada é um token do tipo numero. A função faz isso usando o intervalo dos número em ASCII.
    Para isso, é preciso verificar todo intervalo que é um número na entrada. Ex 456 é um número, então preciso analisar ele como um todo
    e não analisar 4, 5 e 6 separadamente.
    */ 
    while(int(entrada[i]) >= 48 && int(entrada[i]) <= 57){
        i++;
    }
    return i;
}

int ehVariavel(string entrada, int i){
    /* Função que verifica que a entrada é um token do tipo variavel. Para isso, é preciso verificar todo intervalo da entrada que faz parte da variavel,
    ou seja, é preciso ver todas as letras e números depois das letras que são do tipo variavel.
    
     */

    
    while((int(entrada[i]) >= 48 && int(entrada[i]) <= 57) || (int(entrada[i]) >= 65 && int(entrada[i]) <= 90) || (int(entrada[i]) >= 97 && int(entrada[i]) <= 122)){
        i++;
    }
   
    return i;
}

void ehOp(char entrada){
    // Função que verifica que a entrada é um token do tipo operação

    if(entrada == '+'){
        cout << "<MAIS>\n";
    }else if(entrada == '-'){
        cout << "<MENOS>\n";
    }else if(entrada == '/'){
        cout << "<DIVISÃO>\n";
    }else if(entrada == '*'){
        cout << "<MULTIPLICAÇÃO>\n";
    }

}

void externos(char entrada){
    /*
    Essa função irá verificar se o caracter é [] {} () e associar aos tokens. Será feito verificando os intervalos,
    caso esteja no intervalo desses 'externos', então está dentro da possibilidade de ser um token valido.*/


    if (int(entrada) >= 123 && int(entrada) <= 125){ //Está no intervalo das chaves
        if(entrada == '{'){
            cout << "<ABRE-CHAVES>\n";
        }else if(entrada == '}'){
            cout << "<FECHA-CHAVES>\n";
        }
    }
    else if (int(entrada) >= 91 && int(entrada) <= 93){ //Está no intervalo dos colchetes
        if(entrada == '['){
            cout << "<ABRE-COLCHETES>\n";
        }else if(entrada == ']'){
            cout << "<FECHA-COLCHETES>\n";
        }
    }else{ //Está no intervalo dos parênteses
        if(entrada == '('){
            cout << "<ABRE-PARÊNTESES>\n";
        }else if(entrada == ')'){
            cout << "<FECHA-PARÊNTESES>\n";
        }
    }   
}


bool verificaExternos(char entrada){
    // Função para facilitar a verificação do intervalo dos externos. É melhor assim do que pela tabela ASCII, pois os intervalos são diferentes e não seguidos.
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

bool erro(bool flag1, bool flag2, bool flag3, bool flag4){

    if(flag1 == true && flag2 == flag3 == flag4 == false){
        
        return false; //Não tem erro
    }else{
        return true;
    }

}


int main(){
  
    char var[100];
    int saida, i = 0;
    string entrada;
    FILE *arq;
    bool variavelFlag = false, numeroFlag = false, externosFlag = false, operacaoFlag = false, paradaFlag = false;
    
    arq = fopen("arquivoTeste.txt", "r"); //Faço abertura do documento para análise
    if(arq == NULL){
        cout << "Erro ao abrir o arquivo! verifique o nome do mesmo.\n";
        exit(1);
    }


    do{
        fgets(var, 100, arq); //Pego uma linha do arquivo
        entrada = var; //coloco essa linha como string, pois algumas funções necessita de toda essa string, como a verificação de número e variavel.
        cout << "Analisando: " << entrada << "\n";
        numeroFlag = variavelFlag = operacaoFlag = externosFlag = false;

        for(i = 0; i < entrada.size(); i++){
            
            if(int(entrada[i]) >= 48 && int(entrada[i]) <= 57){//Intervalo em ASCII dos números
                saida = ehNumero(entrada, i);
                i = saida - 1; //Como a função ehNumero percorre a string, é preciso atualizar o valor de i. O -1 se deve pelo fato de ele parar quando o caracter
                // não é mais um número, então preciso 'retornar' uma casa para verificar a proxima. Exemplo: 123+x, nesse caso a função pararia em + e pularia para x
                // logo em seguida, o que é um erro. 
                numeroFlag = true;
                paradaFlag = erro(numeroFlag, variavelFlag, externosFlag, operacaoFlag);
                if(paradaFlag == false){
                    cout << "<NUM>\n";
                    continue;//Pulo para o próximo laço
                }else{
                    cout << "Erro!, era esperado 1234567890 \n";
                    break;
                }
            }else if((int(entrada[i]) >= 65 && int(entrada[i]) <= 90) || (int(entrada[i]) >= 97 && int(entrada[i]) <= 122)){//Intervalo em ASCII das letras minúsculas e maiúsculas
                saida = ehVariavel(entrada, i);
                i = saida - 1; // forma análoga à verificação dos números
                variavelFlag = true;

                paradaFlag = erro(variavelFlag, numeroFlag, externosFlag, operacaoFlag);
                if(paradaFlag == false){
                    cout << "<VARIÁVEL>\n";
                    continue; 
                }else{
                    cout << "Erro! Era esperado abcdefghijklmnopqrstuvwxyz1234567890\n";
                    break;
                }
                
            }else if(entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '/' || entrada[i] == '*'){
                operacaoFlag = true;
                paradaFlag = erro(operacaoFlag, numeroFlag, externosFlag, variavelFlag);
                if(paradaFlag == false){
                    ehOp(entrada[i]);
                    continue; 
                }else{
                    cout << "Erro! Era esperado *-/+\n";
                    break;
                }

            }else if(verificaExternos(entrada[i])){
                externosFlag = true;

                paradaFlag = erro(externosFlag, numeroFlag, operacaoFlag, variavelFlag);
                if(paradaFlag == false){
                    externos(entrada[i]);
                    continue; 
                }else{
                    cout << "Erro! Era esperado (){}[]\n";
                    break;
                }

            }else{
                if(entrada[i] == '\n'){
                    break; //Significa o fim da verificação desse linha
                }else if(entrada[i] == ' '){
                    //Significa o fim de um símbolo.
                    numeroFlag = variavelFlag = operacaoFlag = externosFlag = false;
                    continue;
                }

                cout << "Entrada inválida!\n";
                cout << "Carcteres esperados: 1234567890abcdefghijklmnopqrstuvwxyz+-*/(){}[] caracter recebido: " << entrada[i] << "\n";
                break; //A verificação da linha termina caso haja erro
            }
            
        }
    }while(!feof(arq));


    fclose(arq); //fechamento de arquivo

    return 0;
}

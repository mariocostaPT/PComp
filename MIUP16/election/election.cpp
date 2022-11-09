#include <bits/stdc++.h>


#define ll long long
#define ld long double

using namespace std;

class DadosPartidos {
    public:
        std::vector<double> votos;
        std::vector<double> lugares_Sentados;
        std::vector<double> quociente;
        
        
        double alg(int index){
            return (this->votos[index] / (this->lugares_Sentados[index] + 1));
        }
        
        int empate_checker(int quoIndex){
            //numero de partidos
            int size = this->votos.size();

            //loop pela bd            
            for (int x = 0; x < size; x++){
                //se for o index que achamos damos skip
                if (x == quoIndex){
                    continue;
                } else {
                    //se nao comparamos a ver se o valor de cada quo é igual ao que ja temos
                    if(this->quociente[x] == this->quociente[quoIndex]){
                        //primeiro caso foi empate vamos comparar o segundo
                        int less_votes_indx = this->lessVotes(size, quoIndex);
                        int prova = empate_votos(size, less_votes_indx);
                        
                        //caso existir segundo empate
                        if (prova != -1){
                            this->lugares_Sentados[prova] = this->lugares_Sentados[prova] + 1;
                            return prova;
                        } else {
                            this->lugares_Sentados[less_votes_indx] = this->lugares_Sentados[less_votes_indx] + 1;
                            return less_votes_indx;
                        }
                    }
                }
            }
            //o quoIndex é a escolha certa
            return -1;
        }
        
        int lessVotes(int n, int idx){
            
            int menor_idx = idx;
            //max value de votos
            int menos = this->votos[idx];
            
            for(int i = 0; i < n; i++){
                if(this->votos[i] < menos && this->quociente[i] == this->quociente[idx]){
                    menos = this->votos[i];
                    menor_idx = i;
                }
            }
            return menor_idx;
        }
    
        int empate_votos(int size, int less){
            
            for (int i = 0; i < size; i++){
                if (i == less){
                    continue;
                } else {
                    //verificamos se o partido tem os memos votos e se o index é menor
                    if( (this->votos[i] == this->votos[less]) && (i < less) && (this->quociente[less] == this->quociente[i]) ){
                        return i;
                    }
                }
            }
            return -1;
        }
};

int main ()
{
    //le Votos e Numero Partidos
    ll S, P;

    cin >> S >> P;

    //cria tratador de dadosPartidos
    
    DadosPartidos dp;
    double input;

    if(P == 1){
        cout << S << '\n';
        return 0;
    }
    //preenche numero de votos e inicializa n lugares sentados
    while (cin >> input){
        dp.votos.push_back(input);
        dp.lugares_Sentados.push_back(0);
    }
    
    //recebe n partidos    
    int n = dp.votos.size();
    
    //var para o loop
    int index = 0;
    int maiorQuociente = 0;
    int qIndex = -1, empate = 0;
    
    //vamos percorrer até não haver mais lugares
    for (int a = 1; a <= S; a++){
        
        while(index < n){
            //vamos dar push aos quociente
            dp.quociente.push_back( dp.alg(index) );
            if(index == 0){
                maiorQuociente = dp.quociente[index];
                qIndex = 0;
            } else {
                if(dp.quociente[index] > maiorQuociente){
                    maiorQuociente = dp.quociente[index];
                    qIndex = index;
            }
            
            }
            
            //verificamos quociente

            index++;
        }
        maiorQuociente = 0;
        
        empate = dp.empate_checker(qIndex);
        
        if(empate == -1){
            dp.lugares_Sentados[qIndex] = dp.lugares_Sentados[qIndex] + 1;
        }
        //reset
        index = 0;
        dp.quociente.clear();
        maiorQuociente = 0;
        empate = 0;
        qIndex = -1;
    }
    
    for (auto x: dp.lugares_Sentados){
        cout << x << '\n';
    }
    
    return 0;   
}
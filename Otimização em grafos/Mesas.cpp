/*Neste programa você vai trabalhar com o problema do Grande Jantar.
1. Complete a função CriaRede() que cria a rede.
2. Complete a função TemSol que verifica se o problema foi resolvido.
3. Complete a função MostraResultado, que imprime a alocação de pessoas às mesas.
4. Rode o programa para o exemplo de sala.
*/
#include <iostream>
#include<stdlib.h>
#include<string.h>
#define INF 0x3f3f3f3f
#define NVM 1200
using namespace std;

int C[NVM][NVM], CC[NVM][NVM], F[NVM][NVM], n, m, fmax, nt, pt[100], nm, lm[100];
bool V[NVM];  

void Imprime(){
        cout<<"Fluxo:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (F[i][j] > 0) cout << i << " " << j << "  "<<F[i][j]<<endl;
            }        
        }     
}
void ImprimeC(){
        cout<<"Rede:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (CC[i][j] > 0) cout << i << " " << j << "  "<<CC[i][j]<<endl;
            }        
        }     
}

int ExisteCaminho(int v, int s, int mincap) {
    V[v] = true; 
    if (v==s) return mincap;
    for(int i=1; i<=n; i++) {
        if (!V[i] && C[v][i] > 0) {
            if (int fm = ExisteCaminho(i, s, min(mincap, C[v][i]))) {
                C[v][i] -= fm;  C[i][v] += fm;
                F[v][i] += fm;  F[i][v] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}
void CriaRede(){
    int i, j;
    n = 2+nt+nm;
    m = nt+nt*nm+nm;
	for(i=1; i<=n; i++) for (j=1; j<=n; j++){ 
		CC[i][j]=0;  
		F[i][j]=0; 
	}
	for (i=1;i<=nt;i++){ 			//fonte
		CC[1][i+1] = pt[i];
	}
	for (i=2;i<=nt+1;i++){			//times
		for(j=nt+2;j<=nt+m+1;j++){
			CC[i][j]=1;
	        }
	}
	for (i=nt+2;i<=nt+nm+1;i++){			//mesas
	    CC[i][nt+nm+2]=lm[i-nt-2];
	}
	ImprimeC();
    /*Dicas para a criação da rede
        1. A fonte é o vértice 1
        2. Os times são os vértices 2 a nt+1
        3. As mesas são os vértices nt+2 a nt+m+1
        4. O sumidouro é o vértice n=nt+nm+2;   
		Preencher apenas o vetor de capacidades CC.    
    */
    

}
bool TemSol(){
    int i, tp;
    /* Esta função deve verificar se o problema foi resolvido, isto é,
       se todas as pessoas de todos os times foram alocadas às mesas.
    */
    

}
void MostraResultado(){
    int i, j;
    /* Dica: imprimir para cada mesa os times cujas arestas de fluxo (vetor F)
	   são positivas para essa mesa.
	   A saida deve ser assim:
	   Mesa 1: 1 3 5  (na mesa 1 sentaram 3 pessoas: uma do time 1, 1 do time 3 e 1 do 5.
	   ....    
    */

}

int main() {
    while(true){
       cout<<endl<<"Numero de times: "; 
	   cin>>nt;
       cout<<"Pessoas por time: ";
       for(int i=1; i<=nt; i++) cin>>pt[i];
       cout<<"Numero de mesas: "; 
	   cin>>nm;
       cout<<"Lugares nas mesas: ";
       for(int i=1; i<=nm; i++) cin>>lm[i];
       CriaRede();

       cout<<" n= "<<n<<" m= "<<m<<endl;
       for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
           C[i][j]=CC[i][j];
       fmax = 0;
       memset(V, 0, sizeof(V));           
       while(int fm = ExisteCaminho(1, n, INF)) {
           fmax += fm;
           memset(V, 0, sizeof(V));
       }         
       cout<<"Fluxo Maximo = "<<fmax<<endl;
       if (TemSol()) MostraResultado();             
       cin.get();
    }    
}


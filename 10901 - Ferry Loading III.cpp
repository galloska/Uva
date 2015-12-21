#include <bits/stdc++.h>
#define pii pair<int,int>
#define PQ priority_queue<pii , vector<pii> , greater<pii> >

using namespace std;

//Uso priority queue para que los ordene por menor tiempo
//Ya que nunca me garantizan que la entrada me la dan en orden creciente

const int LEFT = 0;
const int INF = 1e8;
const int RIGHT = 1;
const int MAXN = 10005;

char cad[10];
int res[MAXN];

void Derecha(int& act,int& side,PQ& R,PQ& L,queue<int>& q,int& t,int& mini){
	act = mini;

	if(side==LEFT){ // Movernos al otro lado
		side = 1 - side;
		act += t;
	}

	while(!R.empty() && R.top().first<=act){
		q.push( R.top().second );
		R.pop();
	}

	if(q.empty()) act = R.top().first; //Esperamos al sig en la cola

	while(!R.empty() && R.top().first<=act){ // Este lo hace si no lo hace en la primera pasada
		q.push( R.top().second );
		R.pop();
	}
}

void Izquierda(int& act,int& side,PQ& R,PQ& L,queue<int>& q,int& t,int& mini){
	act = mini;

	if(side==RIGHT){ // Movernos al otro lado
		side = 1 - side;
		act += t;
	}

	while(!L.empty() && L.top().first<=act){
		q.push( L.top().second );
		L.pop();
	}

	if(q.empty()) act = L.top().first; //Esperamos al sig en la cola

	while(!L.empty() && L.top().first<=act){
		q.push( L.top().second );
		L.pop();
	}
}

int main(){
	int t,n,m,a,T;
	scanf("%d",&T);

	for(int j=0;j<T;j++){
		scanf("%d %d %d",&n,&t,&m);
		PQ L,R;

		for(int i=0;i<m;i++){
			scanf("%d",&a);
			scanf("\n%s",cad);

			if(cad[0]=='l')
				L.push( pii( a , i ) );
			else
				R.push( pii( a , i ) );
		}

		int act = 0;
		int side = LEFT;
		queue<int> q;

		while(!L.empty() || !R.empty()){

			int mini = INF;
			if(!L.empty()) mini = min( mini , L.top().first );
			if(!R.empty()) mini = min( mini , R.top().first );


			if(mini<=act){ // Verificamos que al menos haya un carro que tomar
				if(side==LEFT && !L.empty() && L.top().first<=act)
					while(!L.empty() && L.top().first<=act && q.size()<n){
						q.push( L.top().second );
						L.pop();
					}
				else if(side==RIGHT && !R.empty() && R.top().first<=act)
					while(!R.empty() && R.top().first<=act && q.size()<n){
						q.push( R.top().second );
						R.pop();
					}
				else if(!L.empty() && L.top().first<=act){
					side = 1 - side;
					act += t; //Nos encontramos en el otro lado
					while(!L.empty() && L.top().first<=act && q.size()<n){
						q.push( L.top().second );
						L.pop();
					}
				}
				else{
					side = 1 - side;
					act += t; //Nos encontramos en el otro lado
					while(!R.empty() && R.top().first<=act && q.size()<n){
						q.push( R.top().second );
						R.pop();
					}
				}
			}
			else{
				if(L.empty()) // Tenemos que agarra de la derecha forzozamente
					Derecha( act , side , R , L , q , t , mini );
				else if(R.empty()) // Tenemos que agarra de la izquierda forzozamente
					Izquierda( act , side , R , L , q , t , mini );
				else if(mini==R.top().first) // Nos quedamos con el siguiente mas cercano en tiempo
					Derecha( act , side , R , L , q , t , mini );
				else Izquierda( act , side , R , L , q , t , mini );
			}

			act += t;// Hacemos el viaje de regreso
			side = 1 - side;
			//Descargamos los carros
			while(!q.empty()){
				res[ q.front() ]  = act;
				q.pop();
			}
		}

		if(j) printf("\n");
		for(int i=0;i<m;i++)
			printf("%d\n",res[i]);
	}
	return 0;
}

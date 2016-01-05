#include <bits/stdc++.h>
#define lli long long int
#define pii pair<int,int>
#define B 33

using namespace std;

const int INF = 1e8;
const int MAXN = 100005;
const double ERROR = 1e-9;

string cad,aux;

int main(){
	int t;
	vector<lli> pot(MAXN);

	pot[0] = 1;
	for(int i=1;i<MAXN - 1;i++)
		pot[i] = pot[i-1] * B;

	cin>>t;
	while(t--){
		cin>>cad;

		vector<lli> h( cad.size() , 0 );

		for(int i=cad.size()-1;i>=0;i--)
			if(i==cad.size()-1) h[i] = cad[i];
			else h[i] = h[i+1] * B + cad[i];

		int q;
		cin>>q;
		while(q--){
			cin>>aux;
			vector<lli> h2( aux.size() , 0 );
			for(int i=aux.size()-1;i>=0;i--)
				if(i==aux.size()-1) h2[i] = aux[i];
				else h2[i] = h2[i+1] * B + aux[i];

			bool flag = false;
			for(int i=0;i+aux.size()-1<cad.size() && !flag;i++){
				lli S;
				int fin = i + aux.size() - 1;
				int ini = i;
				if(fin+1==cad.size()) S = h[ini];
				else S = h[ini] - h[fin+1] * pot[ fin - ini + 1 ];
				if(h2[0]==S) flag = true;
			}
			if(flag) printf("y\n");
			else printf("n\n");
		}
	}
	return 0;
}

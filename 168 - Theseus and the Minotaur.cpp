#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int main(){

	string cad;
	while(getline(cin,cad) && cad!="#"){

		int M,T,k=0;
		bitset<MAXN> v;
		vector< vector<int> > lista( MAXN , vector<int>() );

		for(int i=0;cad[i];i++){
			char a = cad[i];
			if(a==' '){
				i++;
				while(cad[i]==' ') i++;
				M = cad[i];
				i++;
				while(cad[i]==' ') i++;
				T = cad[i];
				i++;
				while(cad[i]==' ') i++;
				while(cad[i]){
					k = k * 10 + (cad[i] - 48);
					i++;
				}
				break;
			}
			i+=2;
			while(cad[i]!=';' && cad[i]!='.'){
				lista[a].push_back(cad[i]);
				i++;
			}
		}

		int cont = 0;
		while(1){
			char P = M;
			for(int i=0;i<lista[M].size();i++){
				int u = lista[M][i];
				if(!v[u] && u!=T){
					M = u;
					break;
				}
			}
			T = P;
			if(M==T) break;
			cont++;
			if(cont==k){
				v[T] = true;
				cont = 0;
				printf("%c ",T);
			}
		}
		printf("/%c\n",M);
	}
	return 0;
}

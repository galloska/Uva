#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int cont[MAXN];
char cad[MAXN][MAXN];

int main(){
	int n,m,a,b,t;
	scanf("%d",&t);

	for(int u=1;u<=t;u++){

		scanf("%d %d %d %d",&n,&m,&a,&b);
		fill( cont , cont + MAXN , 0 );

		for(int i=0;i<n;i++){
			scanf("\n%s",cad[i]);
			for(int j=0;j<m;j++)
				cont[cad[i][j]]++;
		}

		int res = 0;
		vector<int> aux;
		for(int i=0;i<MAXN;i++)
			aux.push_back(cont[i]);

		sort(aux.begin() , aux.end());

		int j = aux.size() - 1;

		while(j>=0 && aux[j]==aux[ aux.size() - 1 ]){
			res += aux[j] * a;
			j--;
		}

		for(int i=0;i<=j;i++)
			res += aux[i] * b;

		printf("Case %d: %d\n",u,res);
	}
	return 0;
}

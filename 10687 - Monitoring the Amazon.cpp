#include <bits/stdc++.h>
#define pii pair<int,int>
#define psi pair<pii,int>

using namespace std;

const int INF = 1e8;
const int MAXN = 1005;

pii num[MAXN];

int Distancia(pii a,pii b){
	return ( a.first - b.first )*( a.first - b.first ) + ( a.second - b.second )*( a.second - b.second );
}

int main(){
	int n;
	while(scanf("%d",&n) && n){

		vector< vector<int> > lista( n , vector<int>() );
		for(int i=0;i<n;i++)
			scanf("%d %d",&num[i].first,&num[i].second);

		for(int i=0;i<n;i++){
			vector<pii> dist;
			for(int j=0;j<n;j++)
				if(j!=i)
					dist.push_back( pii( Distancia( num[i] , num[j] ) , j ) );

			sort( dist.begin() , dist.end() );

			vector<psi> aux;
			for(int j=0;j<n;j++)
				if(j!=i && dist.size() && Distancia( num[i] , num[j] )==dist[0].first)
					aux.push_back( psi( num[j] , j ) );

			sort( aux.begin() , aux.end() );
			for(int j=0;j<aux.size() && lista[i].size()<2;j++)
				lista[i].push_back(aux[j].second);

			aux.clear();
			for(int j=0;j<n;j++)
				if(j!=i && dist.size()>1 && Distancia( num[i] , num[j] )==dist[1].first)
					aux.push_back( psi( num[j] , j ) );

			sort( aux.begin() , aux.end() );
			for(int j=0;j<aux.size() && lista[i].size()<2;j++)
				lista[i].push_back(aux[j].second);
		}

		queue<int> q;
		vector<int> dist( n , INF );
		q.push(0);
		dist[0] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();

			for(int i=0;i<lista[u].size();i++){
				int v = lista[u][i];
				if(dist[u]+1<dist[v]){
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		bool flag = true;

		for(int i=0;i<n;i++)
			if(dist[i]==INF)
				flag = false;

		if(flag) printf("All stations are reachable.\n");
		else printf("There are stations that are unreachable.\n");
	}
	return 0;
}

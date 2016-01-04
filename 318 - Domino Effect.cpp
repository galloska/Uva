#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int INF = 1e8;
const double ERROR = 1e-9;

int main(){
	int n,m,u=1,a,b,c;
	while(scanf("%d %d",&n,&m)){
		if(!n && !m) return 0;

		vector< vector<pii> > lista( n , vector<pii>() );
		vector< vector<int> > mat( n , vector<int>(n , 0) );

		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			a--,b--;
			mat[a][b] = mat[b][a] = c;
			lista[a].push_back(pii( b , c ));
			lista[b].push_back(pii( a , c ));
		}

		vector<int> dist( n , INF );
		priority_queue<pii , vector<pii> , greater<pii> > q;
		q.push( pii( 0 , 0 ) );
		dist[0] = 0;

		while(!q.empty()){
			int u = q.top().second;
			int d = q.top().first;
			q.pop();
			if(d>dist[u]) continue;

			for(int i=0;i<lista[u].size();i++){
				int v = lista[u][i].first;
				d = lista[u][i].second;
				if(d+dist[u]<dist[v]){
					dist[v] = dist[u] + d;
					q.push( pii( dist[v] , v ) );
				}
			}
		}

		double maxi = 0.0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(mat[i][j]){
					int aux = abs( dist[i] - dist[j] );
					aux = abs( aux - mat[i][j] );
					maxi = max( maxi , (double) max( dist[i] , dist[j] ) + aux / 2.0 );
				}

		int id = -1;
		for(int i=n-1;i>=0;i--)
			if( maxi==(double)dist[i] )
				id = i + 1;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(mat[i][j]){
					int aux = abs( dist[i] - dist[j] );
					aux = aux - mat[i][j];
					if(fabs( maxi - max( dist[i] , dist[j] ) + aux / 2.0 )<ERROR)
						a = i + 1, b = j +1;
				}

		printf("System #%d\n",u++);
		printf("The last domino falls after %.1lf seconds, ",maxi);
		if(id!=-1) printf("at key domino %d.\n",id);
		else printf("between key dominoes %d and %d.\n",a,b);
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int INF = 1e8;

int main(){
	int t,n,m,k,a,b,u,d;
	scanf("%d",&t);

	for(int uu=1;uu<=t;uu++){
		scanf("%d %d %d %d %d",&n,&m,&u,&d,&k);

		vector< vector<int> > mat( n , vector<int>(m , 0) );
		vector< vector<int> > vis( n , vector<int>(m , 0) );
		while(k--){
			scanf("%d %d",&a,&b);
			mat[a][b] = 1;
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				set<pii> s;
				if(i+u<n && j+d<m && !mat[ i + u ][ j + d ]) s.insert( pii( i + u , j + d ) );
				if(i-u>=0 && j+d<m && !mat[ i - u ][ j + d ]) s.insert( pii( i - u , j + d ) );
				if(i+u<n && j-d>=0 && !mat[ i + u ][ j - d ]) s.insert( pii( i + u , j - d ) );
				if(i-u>=0 && j-d>=0 && !mat[ i - u ][ j - d ]) s.insert( pii( i - u , j - d ) );

				swap( u , d );
				if(i+u<n && j+d<m && !mat[ i + u ][ j + d ]) s.insert( pii( i + u , j + d ) );
				if(i-u>=0 && j+d<m && !mat[ i - u ][ j + d ]) s.insert( pii( i - u , j + d ) );
				if(i+u<n && j-d>=0 && !mat[ i + u ][ j - d ]) s.insert( pii( i + u , j - d ) );
				if(i-u>=0 && j-d>=0 && !mat[ i - u ][ j - d ]) s.insert( pii( i - u , j - d ) );
				swap( u , d );

				vis[i][j] = (int) s.size();
			}

		queue<pii> q;
		q.push( pii( 0 , 0 ) );
		vector< vector<int> > dist( n , vector<int>(m , INF) );
		dist[0][0] = 0;

		while(!q.empty()){
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			if(i+u<n && j+d<m && !mat[ i + u ][ j + d ] && dist[i+u][j+d]==INF){
				dist[i+u][j+d] = dist[i][j] + 1;
				q.push(pii( i + u , j + d ));
			}
			if(i-u>=0 && j+d<m && !mat[ i - u ][ j + d ] && dist[i-u][j+d]==INF){
				dist[i-u][j+d] = dist[i][j] + 1;
				q.push(pii( i - u , j + d ));
			}
			if(i+u<n && j-d>=0 && !mat[ i + u ][ j - d ] && dist[i+u][j-d]==INF){
				dist[i+u][j-d] = dist[i][j] + 1;
				q.push(pii( i + u , j - d ));
			}
			if(i-u>=0 && j-d>=0 && !mat[ i - u ][ j - d ] && dist[i-u][j-d]==INF){
				dist[i-u][j-d] = dist[i][j] + 1;
				q.push(pii( i - u , j - d ));
			}

			swap( u , d );
			if(i+u<n && j+d<m && !mat[ i + u ][ j + d ] && dist[i+u][j+d]==INF){
				dist[i+u][j+d] = dist[i][j] + 1;
				q.push(pii( i + u , j + d ));
			}
			if(i-u>=0 && j+d<m && !mat[ i - u ][ j + d ] && dist[i-u][j+d]==INF){
				dist[i-u][j+d] = dist[i][j] + 1;
				q.push(pii( i - u , j + d ));
			}
			if(i+u<n && j-d>=0 && !mat[ i + u ][ j - d ] && dist[i+u][j-d]==INF){
				dist[i+u][j-d] = dist[i][j] + 1;
				q.push(pii( i + u , j - d ));
			}
			if(i-u>=0 && j-d>=0 && !mat[ i - u ][ j - d ] && dist[i-u][j-d]==INF){
				dist[i-u][j-d] = dist[i][j] + 1;
				q.push(pii( i - u , j - d ));
			}
			swap( u , d );
		}

		int odd = 0, even = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(dist[i][j]!=INF && vis[i][j]&1) odd++;
				else if(dist[i][j]!=INF) even++;

		printf("Case %d: %d %d\n",uu,even,odd);
	}
	return 0;
}

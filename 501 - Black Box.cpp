#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30005;

int num[MAXN];
int cant[MAXN];

int main(){
	int t,n,m;

	scanf("%d",&t);

	for(int u=0;u<t;u++){
		scanf("%d %d",&n,&m);

		multiset<int> s;
		s.insert(2000000001);
		s.insert(-2000000001);

		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);

		for(int i=0;i<m;i++)
			scanf("%d",&cant[i]);

		int i = 0 , j = 0;
		int pos = 0,act;
		int next = 1;
		multiset<int>::iterator it, aux;
		if(u) printf("\n");

		while(j<m){
			s.insert( num[i] );
			if(!i){
				pos = 1;
				act = num[i];
				it = s.begin();
				it++;
			}

			if(num[i]<act){
				pos++;
				aux = it;
				aux++;
				if(pos<next && aux!=s.end()){
					it++;
					pos++;
					act = *it;
				}
				else if(pos>next){
					aux = it;
					aux--;
					if(aux!=s.begin()){
						it--;
						pos--;
						act = *it;
					}
				}
			}
			i++;
			if(i!=cant[j]) continue;

			while(i==cant[j] && j<m){
				while(pos<next){
					it++;
					pos++;
					act = *it;
				}
				printf("%d\n",act);
				next++;
				j++;
			}
		}
	}
	return 0;
}

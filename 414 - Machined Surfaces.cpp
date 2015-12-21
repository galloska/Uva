#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

string cad;

int main(){

	int n;
	while(scanf("%d",&n) && n){

		int mini = INF;
		vector<int> total;
		cin.ignore();
		for(int i=0;i<n;i++){
			getline( cin , cad );
			int j = 0, cont = 0;
			while(cad[j] && cad[j]=='X') j++;
			while(cad[j] && cad[j]!='X') j++,cont++;

			mini = min( mini , cont );
			total.push_back( cont );
		}

		int res = 0;
		for(int i=0;i<n;i++)
			res += total[i] - mini;

		printf("%d\n",res);
	}
	return 0;
}

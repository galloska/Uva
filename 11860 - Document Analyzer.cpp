#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	for(int u=1;u<=t;u++){

		string cad;
		int cont = 0;
		vector<int> res;
		map<string,int> check;

		while(1){
			getline( cin , cad );
			if(cad=="END") break;
			string aux = "";
			int j = 0;
			while(cad[j]){

				while(cad[j] && cad[j]>='a' && cad[j]<='z') aux += cad[j++];

				while(cad[j] && (cad[j]<'a' || cad[j]>'z')) j++;

				if(aux.size()){
					if(check.find(aux)==check.end()) check[aux] = cont++;
					res.push_back(check[aux]);
					aux = "";
				}
			}
		}

		vector<int> num(cont);
		int act = 1 , ini = 0, fin = 0;
		num[ res[ ini ] ]++;
		int a = 0,b = res.size() - 1,dif = b - a;

		while(ini<res.size()){
			if(fin==res.size()-1){
				while(ini<res.size()){

					num[ res[ ini ] ]--;
					if( !num[ res[ini] ] ) act--;

					if(act==cont && fin - ini < dif){
						dif = fin - ini;
						a = ini;
						b = fin;
					}

					ini++;
				}

				continue;
			}

			fin++;
			if(!num[ res[ fin ] ]) act++;
			num[ res[ fin ] ]++;

			while( num[ res[ ini ] ] > 1 ){
				num[ res[ ini ] ]--;
				ini++;
			}

			if(act==cont && fin - ini < dif){
				dif = fin - ini;
				a = ini;
				b = fin;
			}
		}

		printf("Document %d: %d %d\n",u,a+1,b+1);
	}
	return 0;
}

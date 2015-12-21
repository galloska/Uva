#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

struct ura{
	string nombre;
	int B,D;
	vector<int> C;
    vector<int> L;
	vector<int> U;

	ura(){}

	ura(string a,int b,int c,int d) : C(d + 1) , L(d + 1) , U(d + 1) {
		nombre = a;
		B = b;
		D = d;
		C[D] = c;
	}

	void pre(){

		C[0] = B;

		for(int i=D-1;i>=1;i--)
			C[i] = C[i+1] * ( U[ i + 1 ] - L[ i + 1 ] + 1 );

		for(int i=1;i<=D;i++)
			C[0] -= C[i] * L[i];

		/*for(int i=0;i<=D;i++)
			printf("%d ",C[i]);
		printf("\n");*/
	}

	int calcula(vector<int> aux){
		int res = C[0];

		for(int i=0;i<aux.size();i++)
			res += aux[i] * C[i + 1];

		return res;
	}

	bool operator < (const ura& cmp) const{
		return D < cmp.D;
	}

};

int main(){

	int n,m,a,B,D;
	string cad;

	cin>>n>>m;

	map<string,int> check;
	vector<ura> otro;

	for(int i=0;i<n;i++){
		cin>>cad>>B>>a>>D;
		ura dato( cad , B , a , D );

		for(int j=1;j<=D;j++)
			cin>>dato.L[j]>>dato.U[j];

		check[cad] = i;
		otro.push_back( dato );
	}

	for(int i=0;i<n;i++)
		otro[i].pre();

	while(m--){
		cin>>cad;

		int id = check[cad];

		vector<int> aux;
		for(int i=0;i<otro[id].D;i++){
			cin>>a;
			aux.push_back(a);
		}

		cout<<cad<<"[";
		for(int i=0;i<aux.size();i++){
			if(i) cout<<", ";
			cout<<aux[i];
		}
		cout<<"] = "<<otro[id].calcula(aux)<<"\n";
	}
	return 0;
}

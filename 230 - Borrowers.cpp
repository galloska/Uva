#include <bits/stdc++.h>
#define pii pair<string,string>

using namespace std;

string A,B;
map<string,string> check;

int main(){

	set<pii> s,d;

	while(1){

		char a;
		bool flag = false;
		A = "";

		while(1){
			scanf("%c",&a);
			A += a;
			if(a=='"' && flag){
				A += '\n';
				break;
			}
			if(a=='"') flag = true;
			if(a=='\n') break;
		}

		if(A=="END\n") break;

		B = "";

		flag = false;
		while(1){
			scanf("%c",&a);
			if(a!=' ') flag = true;
			if(!flag) continue;
			B += a;
			if(a=='\n') break;
		}

		check[A] = B;
		s.insert(pii( B , A ));
	}

	while(1){

		char a;
		cin>>A;
		B = "";

		if(A=="END") break;

		bool flag = false;

		if(A=="BORROW"){
			while(1){
				scanf("%c",&a);
				if(a!=' ') flag = true;
				if(!flag) continue;
				B += a;
				if(a=='\n') break;
			}
			s.erase( pii( check[B] , B ) );
		}
		else if(A=="RETURN"){
			while(1){
				scanf("%c",&a);
				if(a!=' ') flag = true;
				if(!flag) continue;
				B += a;
				if(a=='\n') break;
			}
			d.insert( pii( check[B] , B ) );
		}
		else{
			map<string,int> otro;
			for(auto it : d){
				s.insert(it);
				otro[it.second] = 1;
			}

			string prev = "";
			for(auto it : s){
				A = it.second;
				B = A;
				A.pop_back();
				if(otro.find(B)!=otro.end() && !prev.size())
					cout<<"Put "<<A<<" first\n";
				else if(otro.find(B)!=otro.end())
					cout<<"Put "<<A<<" after "<<prev<<"\n";
				prev = A;
			}
			d.clear();
			cout<<"END\n";
		}
	}
	return 0;
}

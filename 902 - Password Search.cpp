#include <bits/stdc++.h>
#define lli long long int
#define B 257

using namespace std;

const int MAXN = 1000005;

int len;
lli h[MAXN];
lli pot[MAXN];
char cad[MAXN];

lli H(int ini,int fin){
	if(fin+1==len) return h[ini];
	return h[ini] - h[fin+1] * pot[ fin - ini + 1 ];	
}

int main(){
	int n;
	pot[0] = 1;
	for(int i=1;i<MAXN;i++)
		pot[i] = pot[i-1] * B;

	while(scanf("%d\n%s",&n,cad)!=EOF){

		map<lli,int> check;

		len = 0;
		for(int i=0;cad[i];i++,len++);

		for(int i=len-1;i>=0;i--)
			if(i==len-1) h[i] = cad[i];
			else h[i] = h[i+1] * B + cad[i];

		int maxi = 0;
		int id;
		for(int i=0;i+n-1<len;i++){
			check[ H( i , i + n - 1 ) ]++;	
			if( check[ H( i , i + n - 1 ) ] > maxi ){
				maxi = check[ H( i , i + n - 1 ) ];
				id = i;				
			}
		}

		for(int i=0;i<n;i++)
			printf("%c",cad[ id + i ]);
		printf("\n");

		for(int i=0;i<len;i++) cad[i] = '\0';

	}
	return 0;
}

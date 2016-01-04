#include <bits/stdc++.h>

using namespace std;

const int MAXV = 105;
const int MAXN = 50005;

char cad[MAXN];
char mat[MAXV][MAXV];
char car[5] = { 'N' , 'L' , 'S' , 'O' };

int main(){
	int n,m,k;
	while(scanf("%d %d %d",&n,&m,&k) && (n || m || k)){
		for(int i=0;i<n;i++)
			scanf("\n%s",mat[i]);

		scanf("\n%s",cad);

		int dir,a,b;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int h=0;h<4;h++)
					if(mat[i][j]==car[h])
						dir = h , a = i , b = j;

		int cont = 0;
		mat[a][b] = '.';

		for(int i=0;i<k;i++){
			if(cad[i]=='D') dir = ( dir + 1 ) % 4;
			else if(cad[i]=='E') dir = ( dir + 3 ) % 4;
			else{
				if(dir==0){
					if(a-1<0 || mat[a-1][b]=='#') continue;
					a--;
					if(mat[a][b]=='*'){
						cont++;
						mat[a][b] = '.';
					}
				}
				else if(dir==1){
					if(b+1>=m || mat[a][b+1]=='#') continue;
					b++;
					if(mat[a][b]=='*'){
						cont++;
						mat[a][b] = '.';
					}
				}
				else if(dir==2){
					if(a+1>=n || mat[a+1][b]=='#') continue;
					a++;
					if(mat[a][b]=='*'){
						cont++;
						mat[a][b] = '.';
					}
				}
				else if(dir==3){
					if(b-1<0 || mat[a][b-1]=='#') continue;
					b--;
					if(mat[a][b]=='*'){
						cont++;
						mat[a][b] = '.';
					}
				}
			}
		}

		printf("%d\n",cont);
	}
	return 0;
}

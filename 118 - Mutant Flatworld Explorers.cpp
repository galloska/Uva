#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

char cad[MAXN];
bool mat[MAXN][MAXN];
char car[5] = { 'N' , 'E' , 'S' , 'W' };

int main(){
	int n,m,a,b;
	char c;
	scanf("%d %d",&n,&m);

	while(scanf("%d %d %c",&a,&b,&c)!=EOF){
		scanf("\n%s",cad);

		int dir;
		if(c=='N') dir = 0;
		else if(c=='E') dir = 1;
		else if(c=='S') dir = 2;
		else dir = 3;

		bool flag = false;
		for(int i=0;cad[i];i++){
			if(cad[i]=='R') dir = ( dir + 1 ) % 4;
			else if(cad[i]=='L') dir = ( dir + 3 ) % 4;
			else{
				if(dir==0){
					if(b+1>m && !mat[a][b]){
						flag = true;
						mat[a][b] = true;
						break;
					}
					else if(b+1<=m) b++;
				}
				else if(dir==1){
					if(a+1>n && !mat[a][b]){
						flag = true;
						mat[a][b] = true;
						break;
					}
					else if(a+1<=n) a++;
				}
				else if(dir==2){
					if(b-1<0 && !mat[a][b]){
						flag = true;
						mat[a][b] = true;
						break;
					}
					else if(b-1>=0) b--;
				}
				else{
					if(a-1<0 && !mat[a][b]){
						flag = true;
						mat[a][b] = true;
						break;
					}
					else if(a-1>=0) a--;
				}
			}
		}

		for(int i=0;cad[i];i++) cad[i] = '\0';

		printf("%d %d ",a,b);
		if(flag) printf("%c LOST\n",car[dir]);
		else printf("%c\n",car[dir]);
	}
	return 0;
}

#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int MAXN = 1000005;

bitset<MAXN> bs;
vector<lli> primes;

void Criba(lli n){
	for(lli i=2;i<=n;i++)
		if(!bs[i]){
			for(lli j=i*i;j<=n;j+=i)
				bs[j] = true;
			primes.push_back(i);
		}
}

lli Euler(lli N){
	lli id = 0, p = primes[id] , ans = N;
	while(p*p<=N){
		if(N%p==0) ans -= ans / p;
		while(N%p==0) N /= p;
		p = primes[++id];
	}
	if(N!=1) ans -= ans / N;
	return ans;
}

int main(){
	Criba( MAXN - 1 );
	lli n;
	while(scanf("%lld",&n) && n){
		lli total = Euler(n);
		if(n==1) total = 0;
		printf("%lld\n",total);
	}
	return 0;
}

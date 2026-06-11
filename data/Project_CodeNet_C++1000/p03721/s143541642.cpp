#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll N,K;
ll table[SIZE];

int main(){

	scanf("%lld %lld",&N,&K);
	for(int i = 0; i < SIZE; i++){

		table[i] = 0;
	}

	ll a,b;
	for(ll i = 0; i < N; i++){

		scanf("%lld %lld",&a,&b);
		table[a] += b;
	}

	ll sum = 0;
	for(int i = 0; i < SIZE; i++){
		if(table[i] == 0)continue;

		sum += table[i];
		if(sum >= K){

			printf("%d\n",i);
			return 0;
		}
	}

	return 0;
}

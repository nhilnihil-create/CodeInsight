#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N,M;
int table[55];

int main(){

	scanf("%d %d",&N,&M);

	for(int i = 0; i < N; i++){

		table[i] = 0;
	}

	int from,to;

	for(int i = 0; i < M; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;

		table[from]++;
		table[to]++;
	}

	for(int i = 0; i < N; i++){

		printf("%d\n",table[i]);
	}

	return 0;
}

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 105
int table[SIZE];

int main(){

	for(int i = 0; i < SIZE; i++){

		table[i] = 0;
	}

	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);

	for(int i = a; i <= b-1; i++){

		table[i]++;
	}

	int ans = 0;

	for(int i = c; i <= d-1; i++){

		if(table[i] == 1)ans++;
	}

	printf("%d\n",ans);

	return 0;
}

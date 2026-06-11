#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int table[105];

int main(){

	for(int i = 0; i < 105; i++){

		table[i] = 0;
	}

	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);

	table[a]++,table[b]++,table[c]++;

	int ans = 0;
	for(int i = 0; i < 105; i++){

		if(table[i] != 0){
			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}

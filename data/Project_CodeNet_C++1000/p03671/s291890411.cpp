#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int table[3];
	int sum = 0,maximum = -1;

	for(int i = 0; i < 3; i++){

		scanf("%d",&table[i]);
		sum += table[i];
		maximum = max(maximum,table[i]);
	}

	printf("%d\n",sum-maximum);

	return 0;
}

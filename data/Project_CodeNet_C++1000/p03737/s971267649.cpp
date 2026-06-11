#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	char buf[3][11];

	for(int i = 0; i < 3; i++){

		scanf("%s",buf[i]);
		printf("%c",buf[i][0]-32);
	}
	printf("\n");

	return 0;
}

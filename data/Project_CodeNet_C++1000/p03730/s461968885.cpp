#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int A,B,C;
	bool check[105];
	for(int i = 0; i < 105; i++){

		check[i] = false;
	}

	scanf("%d %d %d",&A,&B,&C);

	for(int i = 1; ; i++){

		int tmp = (i*A)%B;

		if(tmp == C){

			printf("YES\n");
			return 0;
		}

		if(check[tmp]){

			printf("NO\n");
			return 0;
		}
		check[tmp] = true;
	}

	return 0;
}

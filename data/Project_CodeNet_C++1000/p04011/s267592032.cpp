#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	int N,K,X,Y;
	scanf("%d %d %d %d",&N,&K,&X,&Y);

	int ans = 0;

	if(K >= N){

		printf("%d\n",N*X);
		return 0;
	}
	ans = K*X+(N-K)*Y;

	printf("%d\n",ans);

	return 0;
}

#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N;
	scanf("%d",&N);

	int maximum = 0,ans = 1;

	for(int i = 2; i <= N; i++){

		int count = 0;
		int tmp = i;

		while(tmp%2 == 0){
			tmp /= 2;
			count++;
		}
		if(maximum < count){
			maximum = count;
			ans = i;
		}
	}

	printf("%d\n",ans);

	return 0;
}

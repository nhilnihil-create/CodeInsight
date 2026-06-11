#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

int N;
ll A[SIZE];

int main(){

	scanf("%d",&N);
	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}

	ll plus,sum;

	if(A[0] <= 0){

		plus = abs(1-A[0]);
		sum = 1;

	}else{

		plus = 0;
		sum = A[0];
	}

	for(int i = 1; i < N; i++){

		sum += A[i];

		if(i%2 == 1){ //マイナス

			if(sum < 0)continue;
			plus += abs(-1-sum);
			sum = -1;

		}else{ //プラス

			if(sum > 0)continue;
			plus += abs(1-sum);
			sum = 1;
		}
	}

	ll minus;

	if(A[0] >= 0){

		minus = abs(-1-A[0]);
		sum = -1;
	}else{

		minus = 0;
		sum = A[0];
	}

	for(int i = 1; i < N; i++){

		sum += A[i];

		if(i%2 == 1){ //プラス

			if(sum > 0)continue;
			minus += abs(1-sum);
			sum = 1;

		}else{ //マイナス

			if(sum < 0)continue;

			minus += abs(-1-sum);
			sum = -1;
		}
	}

	printf("%lld\n",min(plus,minus));

	return 0;
}

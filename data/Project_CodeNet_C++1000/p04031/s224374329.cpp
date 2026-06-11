#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N;
int table[105];

int main(){

	scanf("%d",&N);

	int maximum = -BIG_NUM,minimum = BIG_NUM;

	for(int i = 0; i < N; i++){

		scanf("%d",&table[i]);
		maximum = max(maximum,table[i]);
		minimum = min(minimum,table[i]);
	}

	int ans = BIG_NUM;

	for(int num = minimum; num <= maximum; num++){

		int sum = 0;
		for(int i = 0; i < N; i++){

			sum += (num-table[i])*(num-table[i]);
		}

		ans = min(ans,sum);
	}

	printf("%d\n",ans);

	return 0;
}

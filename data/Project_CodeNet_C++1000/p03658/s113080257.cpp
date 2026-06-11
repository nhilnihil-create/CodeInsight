#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N,K;
	scanf("%d %d",&N,&K);

	vector<int> V;
	int tmp;

	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		V.push_back(tmp);
	}

	sort(V.rbegin(),V.rend());

	int ans = 0;
	for(int i = 0; i < K; i++){

		ans += V[i];
	}

	printf("%d\n",ans);

	return 0;
}

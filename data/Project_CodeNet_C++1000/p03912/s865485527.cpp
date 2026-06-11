#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int N,M;
int V[100010],Vb[100010];
int cnt[100010];

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= N; ++i){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i = 1; i <= 100000; ++i){
		if(!cnt[i]) continue;
		V[i % M] += cnt[i];
		Vb[i % M] += cnt[i] / 2;
	}
	int ans = V[0] / 2;
	if(M % 2 == 0){
		ans += V[M / 2] / 2;
	}
	for(int i = 1; i < (M + 1) / 2; ++i){
		int j = M - i;
		if(V[i] == V[j]){
			ans += V[i];
		}
		else if(V[i] > V[j]){
			ans += V[j];
			ans += min((V[i] - V[j]) / 2,Vb[i]);
		}
		else{
			ans += V[i];
			ans += min((V[j] - V[i]) / 2,Vb[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
#include<stdio.h>
#include<tuple>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 200005;
const int MM = 924844033;

ll D[MX];
int N, M;
ll K;

struct trans{
	int t[MX];
	trans operator*(const trans &l)const{
		trans res;
		for(int i = 1; i <= N-1; i++) res.t[i] = t[l.t[i]];
		return res;
	}
};

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", D+i);
	trans A, B;
	for(int i = 1; i <= N-1; i++) A.t[i] = B.t[i] = i;

	scanf("%d%lld", &M, &K);
	for(int i = 1; i <= M; i++){
		int a;
		scanf("%d", &a);
		swap(A.t[a-1], A.t[a]);
	}
	while(K){
		if( K&1 ) B = B * A;
		A = A*A; K /= 2;
	}
	ll cur = D[1];
	for(int i = 1; i <= N; i++){
		printf("%lld\n", cur);
		int a = B.t[i];
		cur += D[a+1] - D[a];
	}
}

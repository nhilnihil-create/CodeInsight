#include<stdio.h>
#include<queue>
#include<assert.h>
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
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 1 << 20;
const int MM = 1000000007;

int D[MX], X[MX], O[MX];

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", X+i);
		D[X[i]] = i;
	}
	for(int i = 1; i <= N; i++) O[i] = i;
	sort(O+1, O+N+1, [](int l, int r){
		return X[l] < X[r];
	});

	int cur = 1;
	for(int i = 1; i <= N; i++){
		int c = O[i];
		for(int j = 1; j < c; j++){
			while(D[cur]){
				if( D[cur] == c ) return !printf("No\n");
				cur++;
			}
			if( cur > X[c] ) return !printf("No\n");
			D[cur++] = c;
		}
	}
	cur = N*N;
	for(int i = N; i >= 1; i--){
		int c = O[i];
		for(int j = 1; j <= N-c; j++){
			while(D[cur]){
				if( D[cur] == c ) return !printf("No\n");
				cur--;
			}
			if( cur < X[c] ) return !printf("No\n");
			D[cur--] = c;
		}
	}
	printf("Yes\n");
	for(int i = 1; i <= N*N; i++) printf("%d ", D[i]);
	printf("\n");
}

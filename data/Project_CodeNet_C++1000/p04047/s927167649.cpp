#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
int N, Q;
int main() {
	scanf("%d", &N);
	vector<int> L(N * 2);
	rep(i, 0, N * 2)scanf("%d", &L[i]);
	sort(L.begin(), L.end());
	int c = 0;
	rep(i, 0, N)c += L[i * 2];
	printf("%d", c);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<cmath>
#include<deque>
#include<set>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 1000000000

int main() {
	int N, C, K, c = 0, ans = 0;
	scanf("%d%d%d", &N,  &C, &K);
	vector<int> A(N);
	rep(i, 0, N)scanf("%d", &A[i]);
	sort(all(A));
	while (1) {
		int i;
		for (i = c; i < min(C + c, N) && A[i] <= A[c] + K; i++);
		//printf("%d\n", c);
		if (i == N) { ans++; break; }
		c = i--;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}

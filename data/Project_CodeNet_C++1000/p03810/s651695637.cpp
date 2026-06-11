#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



typedef long long ll;
//ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return a; }
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int N;
int A[101010];
//-----------------------------------------------------------------
bool sol() {
	if (N == 1) return A[0] % 2 == 0;

	int even = 0;
	rep(i, 0, N) if (A[i] % 2 == 0) even++;

	if (even % 2 == 1) return true;
	if (2 <= N - even) return false;

	int sit;
	rep(i, 0, N) if (A[i] % 2 == 1) sit = i;
	if (A[sit] == 1) return false;
	A[sit]--;

	ll g = A[0];
	rep(i, 0, N) g = gcd(g, A[i]);
	rep(i, 0, N) A[i] = A[i] / g;

	return !sol();
}
//-----------------------------------------------------------------
int main() {
	cin >> N;
	rep(i, 0, N) scanf("%d", &A[i]);

	if (sol())
		printf("First\n");
	else
		printf("Second\n");
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1003;
int N;
int T[MAX_N];
int A[MAX_N];

void solve()
{
	ll a=T[0],b=A[0];
	for(int i=1;i<N;++i){
		ll p = T[i], q = A[i];
		//np>=a && nq>=b
		const ll n = max((a+p-1)/p,(b+q-1)/q);
		a=n*p,b=n*q;
	}
	cout << a+b;
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i) cin >> T[i] >> A[i];
	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+12;
int N, T;
ll A[MAX_N];

void solve()
{
	set<ll> prices;
	ll mx = 0, mc = -1;
	for(int i=0;i<N;++i){
		auto it = prices.begin();
		if(it != prices.end() && *it < A[i]){
			if(mx < (A[i]-(*it))){
				mx = A[i]-(*it);
				mc=1;
			}else if(mx == (A[i]-(*it))){
				mc++;
			}
		}
		prices.insert(A[i]);
	}
	cout << mc << '\n';
}

int main()
{
	cin >> N >> T;
	for(int i=0; i<N; ++i) cin >> A[i];
	solve();
	return 0;
}
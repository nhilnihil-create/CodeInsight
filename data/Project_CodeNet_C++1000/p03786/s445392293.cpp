#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	sort(A.begin(),A.end());
	ll sum = 0;
	ll cnt = 0;
	rep(i,N) {
		if(sum * 2 >= A[i]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		sum += A[i];
	}
	cout << cnt << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int n = s.size();
	ll cnt[26] = {0,};
	rep(i,0,n) {
		int c = s[i] - 'a';
		cnt[c]++;
	}
	ll ret = (ll)n*(n-1)/2+1;
	rep(i,0,26) {
		ll m = cnt[i];
		ret -= m*(m-1)/2;
	}
	cout << ret << endl;
	return 0;
}
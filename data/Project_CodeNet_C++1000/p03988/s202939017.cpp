#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
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
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	bool flag = true;
	int cnt = 0;
	vector<bool> b(n, false);
	rep(i,0,n) {
		b[a[i]] = true;
		if(i == 0 || a[i] == a[i-1]) {
			cnt++;
		} else {
			if(cnt == 1) {
				flag = false;
				break;
			}
			cnt = 1;
		}
	}
	rep(i,(a[0]+1)/2, a[0]) {
		flag = flag && b[i];
	}
	if((a[0]+1) % 2) {
		if(cnt != 1) flag = false;
	} else {
		if(cnt != 2) flag = false;
	}
	if(flag) {
		cout << "Possible" << '\n';
	} else {
		cout << "Impossible" << '\n';
	}
	return 0;
}

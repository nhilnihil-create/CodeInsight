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
	int a, prev, flag = 0, flag2 = true;
	cin >> prev;
	int cnt = 0;
	rep(i, N-1) {
		cin >> a;
		//cout << a << " " << prev << " " << flag << endl;
		if(flag2) {
			if(a == prev) {
				prev = a;
				continue;
			}
			if(a < prev) flag = -1;
			if(a > prev) flag = 1;
			prev = a;
			flag2 = false;
			continue;
		}
		if(flag == -1 && a > prev) {
			cnt++;
			flag2 = true;
		}
		else if (flag == 1 && a < prev) {
			cnt++;
			flag = -1;
			flag2 = true;
		}
		prev = a;
	}
	cout << cnt+1 << endl;
	

  return 0;
}

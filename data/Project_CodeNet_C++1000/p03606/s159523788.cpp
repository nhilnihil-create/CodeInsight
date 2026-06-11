#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	int l[n], r[n];
	rep (i, n) cin >> l[i] >> r[i];

	vector<ll> sum(100010, 0);
	rep (i, n) {
		sum[l[i] - 1]++;
		sum[r[i]]--;
	}

	rep (i, 100005) sum[i + 1] += sum[i];
	int cnt = 0;
	rep (i, 100001) if (sum[i]) cnt++;

	cout << cnt << endl;
	return 0;
}
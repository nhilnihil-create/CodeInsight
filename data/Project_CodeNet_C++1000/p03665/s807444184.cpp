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
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	rep (i, n) cin >> a[i];

	bool haveodd = false;
	rep (i, n) if (a[i] % 2) haveodd = true;
	
	cout << (haveodd ? 1LL<<n-1: p ? 0 : 1LL<<n) << endl;
	return 0;
}
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int x,a,b; cin >> x >> a >> b;
	if(b<=a) cout << "delicious" << endl;
	else if(b-a<=x) cout << "safe" << endl;
	else cout << "dangerous" << endl;
}
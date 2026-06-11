// https://atcoder.jp/contests/arc071/tasks/arc071_b
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int M = 1e9 + 7;
int add(int a, int b){ return a+b < M ? a+b : a+b-M; }
int mul(int a, int b){ return int(ll(a)*b % M); }
int normal(ll a){ return int(((a % M) + M) % M); } // For neg numbers

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    int sx = 0, sy = 0;
    forsn(i, 1, n+1) {
        ll x; cin >> x;
        sx = add(sx, normal(x * (2*i-1-n)));
    }
    forsn(i, 1, m+1) {
        ll y; cin >> y;
        sy = add(sy, normal(y * (2*i-1-m)));
    }
    cout << mul(sx, sy) << endl;
	return 0;
}

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

int main() {
	fastio;
	
    string a,b; cin >> a >> b;
    int sa = si(a), sb = si(b);
    string ans;
    int ca = 0, cb = 0;
    forn(i, sa+sb) {
        if (i % 2 == 0 || cb == sb) ans += a[ca++]; 
        else ans += b[cb++];
    }
    cout << ans << endl;	
	return 0;
}

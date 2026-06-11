#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

vi perm(ll n) {
    if (n == 1) return vi();

    auto p = perm(n/2);
    p.push_back(si(p));
    if (n%2) {
        for (auto &x : p) x++;
        p.push_back(0);
    }
    return p;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    n++;
    auto p = perm(n);
    cout << 2*si(p) << endl;
    forn(i,si(p)) cout << i+1 << ' ';
    for (auto x : p) cout << x+1 << ' ';
    return 0;
}

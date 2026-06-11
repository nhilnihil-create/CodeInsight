#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

signed main() {
    int H, W;
    cin >> H >> W;
    map<char, int> mp;
    rep(i, H) rep(j, W) {
        char a;
        cin >> a;
        mp[a]++;
    }
    /*rep(i, 26) {
        cout << mp[char(i+'a')] << endl;
    }*/

    int f = (H/2) * (W/2);
    int t = (H%2 ? W/2 : 0) + (W%2 ? H/2 : 0);
    int o = (H%2 && W%2 ? 1 : 0);

    //cout << f  << " " << t << " " << o << endl;

    for(auto &p : mp) {
        if(4*f >= p.se) {
            f -= (p.se/4);
            mp[p.fi] = p.se%4;
        } else {
            mp[p.fi] -= 4*f;
            f = 0;
        }
        if(f==0) break;
    }
    for(auto &p : mp) {
        if(2*t >= p.se) {
            t -= (p.se/2);
            mp[p.fi] = p.se%2;
        } else {
            mp[p.fi] -= 2*t;
            t = 0;
        }
        if(t==0) break;
    }
    /*rep(i, 26) {
        cout << mp[char(i+'a')] << endl;
    }*/

    bool ok = false;
    if(o) {
    for(auto &p : mp) {
        if(ok) {
            if(p.se>=1) {
                ok = false;
                break;
            }
        } else {
            if(p.se==1) ok = true;
            else if(p.se>1) {
                ok = false;
                break;
            }
        }
    }
    } else {
        ok = true;
        for(auto &p : mp) {
            if(p.se) {
                ok = false;
                break;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    

    return 0;
}
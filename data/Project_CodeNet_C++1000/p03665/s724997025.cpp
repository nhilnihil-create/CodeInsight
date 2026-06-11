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

int euq(int a, int b) {return b ? euq(b, a%b) : a;}

int comb(int n, int k) {
    int a=1, b=1;
    k = min(k, n-k);
    vi ar, br;
    rep(i, k) {
        ar.pb(n-i);
        br.pb(i+1);
    }

    rep(i, ar.size()) {
        rep(j, br.size()) {
            int g = euq(ar[i], br[j]);
            ar[i] /= g; br[j] /= g;
        }
    }

    rep(i, ar.size()) a *= ar[i];
    rep(i, br.size()) b *= br[i];
    
    return a/b;
}

signed main() {
    int N, P;
    cin >> N >> P;

    int e=0, o=0;
    rep(i, N) {
        int a;
        cin >> a;
        if(a%2) o++;
        else e++;
    }

    int oc = 0;
    if(P) {
        for(int i=1; i<=o; i+=2) {
            oc += comb(o, i); 
        }
    } else {
        for(int i=0; i<=o; i+=2) {
            oc += comb(o, i);
        }
    }

    int res = 0;
    rep(i, e+1) {
        res += oc*comb(e, i);
    }

    cout << res << endl;

    return 0;
}
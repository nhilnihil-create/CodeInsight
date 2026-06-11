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
    int N, x;
    cin >> N >> x;
    vi res(2*N-1);

    if(x==1 || x==2*N-1) {
        cout << "No" << endl;
        return 0;
    }
    else if(N>2) {
        if(x==2) {
            rep(i, 3) {
                res[(2*N-1)/2-1+i] = x-1+i;
            }
            res[(2*N-1)/2-2] = x+2;
            int a = 5;
            rep(i, (2*N-1)/2-2) res[i] = a++;
            FOR(i, (2*N-1)/2+2, 2*N-1) res[i] = a++;
        } else {
            rep(i, 3) {
                res[(2*N-1)/2-1+i] = x-1+i;
            }
            res[(2*N-1)/2+2] = x-2;
            int a = 1;
            rep(i, (2*N-1)/2-1)  {
                if(a==x-2) a = x+2;
                res[i] = a;
                a++;
            }
            FOR(i, (2*N-1)/2+3, 2*N-1) {
                if(a==x-2) a = x+2;
                res[i] = a++;
            }
        }
    } else {
        rep(i, 3) {
            res[i] = i+1;
        }
    }

    cout << "Yes" << endl;
    rep(i, 2*N-1) {
        cout << res[i] << endl;
    }

    return 0;
}
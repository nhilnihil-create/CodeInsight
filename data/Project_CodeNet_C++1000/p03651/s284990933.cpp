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

signed main() {
    int N, K;
    cin >> N >> K;

    int g=0, mx = 0;
    vi A(N);
    rep(i, N) {
        cin >> A[i];
        g = euq(g, A[i]);
        mx = max(mx, A[i]);
    }

    if(mx < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if(g==1) {
        cout << "POSSIBLE" << endl;
    } else {
        if(K%g==0) {
            cout << "POSSIBLE" << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
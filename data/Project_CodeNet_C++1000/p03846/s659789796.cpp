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

const int MOD = 1e9+7;

signed main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    SORT(A);
    int res = 1;

    bool ok = true;
    if(N%2) {
        if(!A[0]==0) ok = false;
        rep(i, N-1) {
            if(i%2) {res *= 2;
            res %= MOD;}
            if(A[i+1]!=((i/2)+1)*2) ok = false;
        }
    } else {
        rep(i, N) {
            if(i%2) {res *= 2;
            res %= MOD;}
            if(A[i]!=(i/2)*2+1) ok = false;
        }
    }

    if(!ok) res = 0;

    cout << res << endl;
 
    return 0;
}
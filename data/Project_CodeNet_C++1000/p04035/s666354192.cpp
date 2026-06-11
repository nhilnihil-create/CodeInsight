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
    int N, L;
    cin >> N >> L;
    vi A(N);
    rep(i, N) cin >> A[i];

    bool ok = false;
    int tp = 0;
    stack<int> st;
    rep(i, N-1) {
        if(A[i]>=L || A[i]+A[i+1]>=L) {
            ok = true;
            st.push(i+1);
            tp = i+1;
            break;
        }
    }
    if(!ok) {
        cout << "Impossible" << endl;
        return 0;
    } else cout << "Possible" << endl;

    for(int i=tp-1; i>=1; i--) {
        st.push(i);
    }
    for(int i=tp+1; i<=N-1; i++) {
        st.push(i);
    }

    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
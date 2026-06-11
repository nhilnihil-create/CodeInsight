#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

const int N = 222222;
int a[N];
unordered_set<int> st;
int n, x;

void place(int i, int y) {
    a[i] = y;
    st.erase(y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    n = 2 * n - 1;
    if(n == 3) {
        if(x != 2) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << 1 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
        }
    } else {
        if(x == 1 || x == n) {
            cout << "No" << endl;
        } else {
            rep(i, 1, n) {
                st.insert(i);
            }
            int mult = x == 2 ? -1 : 1;
            int m = n + 1 >> 1;
            place(m - 2, x - 2 * mult);
            place(m - 1, x);
            place(m, x + mult);
            place(m + 1, x - mult);
            rep(i, 1, n) {
                if(!a[i]) {
                    a[i] = *(st.begin());
                    st.erase(st.begin());
                }
            }
            cout << "Yes" << endl;
            rep(i, 1, n) {
                cout << a[i] << endl;
            }
        }
    }
    return 0;
}

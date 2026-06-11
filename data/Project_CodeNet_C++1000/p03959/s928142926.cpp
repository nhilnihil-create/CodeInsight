#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n,-1);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    c[0] = a[0];
    c[n-1] = b[n-1];
    if(a[n-1] != b[0]){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            if(c[i]!=-1 && c[i]!=a[i]){
                cout << 0 << endl;
                return 0;
            }else c[i] = a[i];
        }else if(c[i]!=-1 && c[i] >a[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(b[i]>b[i+1]){
            if(c[i]!=-1 && b[i]!=c[i]){
                cout << 0 << endl;
                return 0;
            }else c[i] = b[i];
        }else if(c[i]!=-1 && c[i]>b[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i=0;i<n;i++){
        if(c[i]==-1){
            ans *= min(a[i],b[i]);
            ans %= mod;
        }
    }
    cout << ans << endl;
}

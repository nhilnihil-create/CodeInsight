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
    vector<int> a(n),b;
    rep(i,n)cin >> a[i];
    b = a;
    sort(ALL(b));
    // これで最終的な場所はbになることがわかる
    ll ans = 0;
    for(int i=0;i<n;i++){
        // a[i] について i%2==0 && a[i]がbの偶数番目にあったら0
        int p = lower_bound(ALL(b),a[i]) - b.begin();
        if(i%2==0 && p%2==0)continue;
        if(i%2==1 && p%2==1)continue;
        ans++;
    }
    cout << ans/2LL << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
vector<int> vis(N);
int F(int a, int b){
    int cnt1 = 0, cnt2 = 0;
    while(a){
        cnt1++;
        a /= 10;
    }
    while(b){
        cnt2++;
        b /= 10;
    }
    return max(cnt1, cnt2);
}
void solve(){
    int n;
    cin >> n;
    int ans = INF;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans = min(ans, F(i, n / i));
        }
    }
    cout << ans << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}
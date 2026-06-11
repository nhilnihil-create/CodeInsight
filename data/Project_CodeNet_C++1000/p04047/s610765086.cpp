#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 20;
vector<int> g[N];
vector<int> vis(N);
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        int n;
        cin >> n;
        int a[2 * n];
        for(int i = 0; i < 2 * n; i++){
            cin >> a[i];
        }
        sort(a, a + 2 * n);
        int ans = 0;
        for(int i = 0; i < 2 * n; i += 2){
            ans += a[i];
        }
        cout << ans << '\n';
    }
}
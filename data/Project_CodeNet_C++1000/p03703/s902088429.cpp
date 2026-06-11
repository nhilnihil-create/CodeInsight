#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int &i : a){
            cin >> i;
        }
        int b[n], sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
            b[i] = sum - (i + 1) * k;
        }
        ordered_set<int> s;
        s.insert(0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += s.order_of_key(b[i] + 1);
            s.insert(b[i]);
        }
        cout << ans << '\n';
    }
}
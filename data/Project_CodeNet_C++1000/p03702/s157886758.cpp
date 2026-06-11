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
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> h(n);
        for(int &i : h){
            cin >> i;
        }
        int l = 1, r = 1e9;
        int ans;
        while(l <= r){
            int mid = (l + r) / 2;
            vector<int> curr = h;
            for(int &it : curr){
                it -= b * mid;
            }
            int cnt = 0;
            int left = a - b;
            for(int &it : curr){
                if(it > 0){
                    cnt += (it / left) + (it % left != 0);
                }
            }
            if(cnt <= mid){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}
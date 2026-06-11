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
void solve(){
    int n;
    cin >> n;
    int a[n];
    deque<int> dq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i % 2){
            dq.push_front(a[i]);
        }else{
            dq.push_back(a[i]);
        }
    }
    vector<int> ans;
    while(dq.size()){
        ans.push_back(dq.back());
        dq.pop_back();
    }
    if(n % 2 == 0){
        reverse(ans.begin(), ans.end());
    }
    for(int &i : ans){
        cout << i << ' ';
    }
    cout << '\n';
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
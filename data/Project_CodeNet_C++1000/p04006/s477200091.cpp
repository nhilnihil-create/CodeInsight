#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
const double pi = acos(-1.0);
const double eps = 1e-9;
using namespace std;

const int N = 2e5 + 1;
ll dp[N], a[N];
int n, m;
void solve(){
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = a[i];
        ans += a[i];
    }
    for (int i = 1; i <= n - 1; i++){
        
        for (int j = 0; j < n; j++){
            int from = (j - i + n) % n;
            dp[j] = min(dp[j], a[from]);
        }
        ll res = 0;
        for (int j = 0; j < n; j++) res += dp[j];
        res += (m * 1ll * i);
        ans = min(ans, res);
    }
    cout << ans << endl;
    
}   
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(10);
    //freopen("input.txt", "r", stdin);//freopen("output1.txt", "w", stdout);
    //freopen("icecream.in","r",stdin);// freopen("exam.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++){
         solve();
    }
}

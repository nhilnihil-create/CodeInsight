#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define uint unsigned int
#define ull  unsigned long long
#define pb push_back
#define mk make_pair
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define X first
#define Y second
#define umap unordered_map
#define speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define setvalue(d,s,e,n) for(int qwe = s; qwe < e; ++qwe) d[qwe] = n
#define mset multiset
#define pqueue priority_queue
   
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
        
const int  N = 2e5 + 314;
const int INF = 1e9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const double eps = 1e-9;
ll dp[2050][2050];
ll c[2050];
ll w[2050];
bool cmp(ll a, ll b) {
    return a > b;
}
ll sum1[N],sum2[N],sum3[N], sum4[N];
void solve(){
    ll n,s;
    cin >> n >> s; 
    for(int i = 1; i <= n; ++i)
        cin >> w[i] >> c[i];
    ll mn = *min_element(w + 1, w + n + 1); 
    vector <ll> v1, v2,v3 ,v4;
    for(int i = 1; i <= n; ++i) {
        if(w[i] == mn) {
            v1.pb(c[i]);
        }
        else if(w[i] == mn + 1) {
            v2.pb(c[i]);
        }
        else if(w[i] == mn+ 2){
            v3.pb(c[i]);
        }
        else {
            v4.pb(c[i]);
        }
    }
    sort(rall(v1));
    sort(rall(v2));
    sort(rall(v3));
    sort(rall(v4));
    v1.insert(v1.begin(), 0);
    v2.insert(v2.begin(), 0);
    v3.insert(v3.begin(), 0);
    v4.insert(v4.begin(), 0);
    for(int i = 1; i < v1.size(); ++i) {
        sum1[i] = sum1[i - 1] + v1[i];
    }
    for(int i = 1; i < v2.size(); ++i) {
        sum2[i] = sum2[i - 1] + v2[i];
    }
    for(int i = 1; i < v3.size(); ++i) {
        sum3[i] = sum3[i - 1] + v3[i];
    }
    for(int i = 1; i < v4.size(); ++i) {
        sum4[i] = sum4[i - 1] + v4[i];
    }
    ll mx = 0;
    for(ll i = 0; i < v1.size(); ++i) {
        for(ll j = 0; j < v2.size(); ++j) {
            for(ll k = 0; k < v3.size(); ++k) {
                if(i * mn + j * (mn + 1) + k * (mn + 2) > s)
                    continue;
                ll m4 = (s - (i * mn + j * (mn + 1) + k * (mn + 2)) )/ (mn + 3);
                ll tot = sum1[i] + sum2[j] + sum3[k] + sum4[m4]; 
                mx = max(mx, tot);
            }
        }
    }
    cout << mx;
}
int main(){
    speed();
    int t = 1;
    // cin >> t;
    while(t--)solve();
}
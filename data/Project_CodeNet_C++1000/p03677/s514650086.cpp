#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 1e5 + 1;
vector<ll>  e1[N], s1[N], s2[N], e2[N]; 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(i = 0; i < n; i++){
            cin >> a[i];    
        }
        ll sum = 0;
        vector<ll> sa;
        ll qsum = 0, q2sum = 0, q3sum = 0;
        queue<pair<ll,ll>> q;
        queue<ll> q2, q3;
        multiset<pair<ll,ll>> ab, ba;
        
        for(i = 1; i < n; i++){
            if(a[i] > a[i - 1]){
                sum += a[i] - a[i - 1];
                e1[a[i]].pb(a[i - 1]);
                s1[a[i - 1]].pb(a[i]);
            }
            else{
                sum += (m - a[i - 1] + a[i]);
                e2[a[i - 1]].pb(a[i]);
                s2[a[i]].pb(a[i - 1]);
                ab.insert({a[i - 1], a[i]});
                ba.insert({a[i], a[i - 1]});
            }
        }
        ll curr = sum;
        ll sum2 = 0, sum3 = 0;
        for(auto u : ba){
            q2.push(u.ff);
            sum2 += u.ff;
            curr -= (m - u.ss + u.ff);
        }
        
        ll ans = INF;
        
        
        multiset<pair<ll,ll>> cas1;
        ll sumcas = 0;
        for(ll x = 1; x <= m; x++){
            while(!cas1.empty() && (*cas1.begin()).ff < x){
                sumcas -= (*cas1.begin()).ff;
                curr += (*cas1.begin()).ss;
                cas1.erase(cas1.begin());   
            }
            
            ll currans;
            ll sz1, sz2, sz3;
            sz1 = cas1.size();
            sz2 = q2.size();
            sz3 = q3.size();
            //cout << curr << " " << sz1 << " " << sz2 << " " << sz3 << endl;
            currans = curr + (sz1 + sumcas - sz1 * x) + (sz2 + sum2 - sz2 * x) + (sz3 + sz3 * m - sz3 * x + sum3);
            //cout << currans << endl;
            ans = min(ans, currans);
            for(auto u : s1[x]){
                cas1.insert({u ,u - x});
                sumcas += u;
                curr -= (u - x);
            } 
            while(!ab.empty() && (*(ab.begin())).ff <= x){
                pair<ll,ll> p = *(ab.begin());
                ab.erase(ab.begin());
                q3.push(p.ss);
                sum3 += p.ss;
                curr -= (m - p.ff + p.ss);
            }   
            while(!ba.empty() && (*(ba.begin())).ff <= x){
                pair<ll,ll> p = *ba.begin();
                ba.erase(ba.begin());
                q2.pop();
                sum2 -= p.ff;
                curr += (m - p.ss + p.ff);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
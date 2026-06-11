#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    vector<ll> rui(s.size());
    if(s[0] == 'p')rui[0] = 1;
    else rui[0] = 0;

    rep(i, s.size()-1){
        rui[i+1] = rui[i];
        if(s[i+1] == 'p')rui[i+1]++;
    }

    ll ans = 0;
    ll g_p = 0;
    rep(i, s.size()){
        if(s[i] == 'g'){
            if(g_p > rui.back() - rui[i]){
                ans++;
                g_p--;
            }
            else{
                g_p++;
            }
        }
        else {
            g_p--;
            if(g_p < 0){
                ans--;
                g_p = 0;
            }
        }
    }

    cout << ans << endl;
}
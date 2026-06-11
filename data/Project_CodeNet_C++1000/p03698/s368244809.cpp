#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    string s;
    cin >> s;
    map<char,ll> m;
    rep(i,0,s.size()){
        if(m.count(s[i]) == 0){
            m[s[i]] = 1;
        }
        else{
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}

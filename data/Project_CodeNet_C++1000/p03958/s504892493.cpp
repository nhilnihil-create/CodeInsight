#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {


    ll k,t,a; cin >> k >> t;
    ll ans = 0;
    ll sum = 0;
    vector<ll> x(t);
    ll l = -1;
    priority_queue<pair<ll,ll>> q;

    rep(i,t){
        cin >> x[i];
        sum += x[i];
        //q.push(make_pair(a,i));
    }

    sort(x.begin(),x.end());

    if(x[x.size()-1] <= sum-x[x.size()-1]) cout << 0;
    else cout << x[x.size()-1] - (sum-x[x.size()-1]) -1;

    /*
    while(!q.empty()){

        pair<ll,ll> tmp = q.top();
        q.pop();
        if(l != tmp.second){
            tmp.first --;
            l = tmp.second;
        }else{
            if(q.size() == 1) break;
            pair<ll,ll> tmp2 = q.top();
            tmp2.first --;
            l = tmp2.second;
            if(tmp2.first != 0) q.push(tmp2);
        }
        if(tmp.first != 0) q.push(tmp);
    }

    if(!q.empty()) ans += q.top().first;
*/
    //cout << ans;


    return 0;
}

#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define len(x) (int)(x).size()

typedef long long ll;
typedef long double ld;

using namespace std;

signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;cin >> n;
    int x;cin >> x;
    ll sum = x, sum1 = 0 , negsum = 0;
    ll pref = -1;
    bool done = 0;
    int kek;
    vector<pair<ll,ll>>neg;
    for(int i = 1; i <n ; ++i){
        char ch;cin >> ch >> x;
        if(ch == '-'){
            neg.pb({sum , x});
            negsum += x;
        }
        sum += x;
    }
    /// first ways
    ll answer = -1e18;
    answer = max(answer , sum - 2 * negsum);
    ll cur = 0;
    for(int i = 0 ; i < len(neg) - 1; ++i){
        ll now = cur + neg[i + 1].fi - neg[i].fi;
        answer = max(answer , sum - 2 * now);
        cur += neg[i].se;
    }
    cout << answer;
    return 0;
}

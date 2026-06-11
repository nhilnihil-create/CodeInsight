#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N;
    cin >> N;
    VL d(N);
    rep(i, 0, N){
        ll a;
        cin >> a;
        a--;
        d[i] = a;
    }
    VB seen(N, false);
    ll ans = 0;
    rep(i, 0, N){
        if(d[d[i]] == i){
            if(!seen[i]){
                ans++;
                seen[d[i]] = true;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}
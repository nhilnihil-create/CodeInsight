#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    vector<vector<ll> > combination(51, vector<ll>(51));
    rep(i,51){
        rep(j,51){
            combination[i][j] = 0;
        }
    }
    rep(i,51){
        combination[i][0] = 1;
        combination[i][i] = 1;
    }
    for (ll i = 2; i <= 50; i++){
        for (ll j = 1; j < i; j++){
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
        }
    }
    
    ll N, B;
    double A;
    cin >> N >> A >> B;
    ll A2 = ll(A + 0.5);
    vector<double> v1(N);
    rep(i,N) cin >> v1[i];
    vector<ll> v2(N);
    rep(i,N) v2[i] = ll(v1[i] + 0.5);
    sort(all(v2));
    sort(all(v1));
    map<ll,ll> mp;
    rep(i,N) mp[v2[i]]++;
    double ans = 0;
    rep(i,A2) ans += v1[N - 1 - i];
    cout << setprecision(15) << ans / A << endl;
    bool same = true;
    rep(i,A2 - 1){
        if (v2[N - i - 1] != v2[N - i - 2]) same = false;
    }
    if (!same){
        ll ans_sub = 0;
        for (ll i = 0; i < A2; i++){
            if (v2[N - i - 1] == v2[N - A2]) ans_sub++;
        }
        cout << combination[mp[v2[N - A2]]][ans_sub] << endl;
    }
    else{
        ll ans2 = 0;
        for (ll i = A2; i <= B; i++){
            if (v2[N - i] == v2[N - 1]) ans2 += combination[mp[v2[N - A2]]][i];
        }
        cout << ans2 << endl;
    }
}
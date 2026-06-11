#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
const ll INF = 1LL<<60;




int main()
{
    int N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
    }
    if(K == 1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = INF;
    for(int tmp = 0; tmp <(1 << N) ;tmp++){
        bitset<15> bs(tmp);
        if(bs.count() != K || !bs.test(0)) continue;
        //cout << bs << endl;  
        ll tmp_a = a[0];
        ll cost = 0;
        rep2(i,1,N){
            if(bs.test(i)){
                if(tmp_a>=a[i]){
                    tmp_a = tmp_a + 1;
                    cost += tmp_a -  a[i];
                }
                else tmp_a = a[i];
            }
            else tmp_a = max(tmp_a, a[i]);
        }
        ans = min(ans,cost);
    }

    cout << ans << endl;

    return 0;
}
//Ctrl+Shift+Bでコンパイルと実行を行ってデバッグすること
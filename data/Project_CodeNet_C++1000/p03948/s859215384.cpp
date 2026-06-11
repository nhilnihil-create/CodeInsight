#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,T;
    cin >> N >> T;
    ll mini = INF, dif = 0, ans = 0;
    rep(i,0,N){
        ll a;
        cin >> a;
        mini = min(mini, a);
        if(dif < a - mini){
            dif = a - mini;
            ans = 1;
        }else if(dif == a - mini){
            ans++;
        }
    }
    cout << ans << endl;
}
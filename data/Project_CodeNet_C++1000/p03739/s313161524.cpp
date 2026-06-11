#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<ll> v(n,0);
    rep(i,n) cin >> v[i];
    ll ans = 0;
    rep(i,2){
        ll now = 0;
        ll sum = 0;
        rep(j,n){
            if(i == 0){
                sum += v[j];
                if(j%2 == 0){
                    //正にしたい
                    if(sum <= 0){
                        now += 1 - sum;
                        sum = 1;
                    }
                }else{
                    //負にしたい
                    if(sum >= 0){
                        now += sum + 1;
                        sum = -1;
                    }
                }
            }else{
                sum += v[j];
                if(j%2 == 0){
                    if(sum >= 0){
                        now += sum + 1;
                        sum = -1;
                    }
                }else{
                    if(sum <= 0){
                        now += 1 - sum;
                        sum = 1;
                    }
                }
            }
        }
        if(i == 0) ans = now;
        else ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=1, tmp1=0, tmp2=0;
queue<ll> Q;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        a--;
        a /= 2;
        Q.push(a);
        //cout << a << " ";
    }
    while(!Q.empty()) {
        ll num = Q.front();
        //cout << tmp1 << " " << num << " " << tmp2 << endl;
        if(tmp1-num>tmp2) {
            ans *= (tmp1+1-tmp2);
            ans %= MOD;
            //cout << (tmp1+1-tmp2) << endl;
            tmp2++;
        }
        else {
            tmp1++;
            Q.pop();
        }
    }
    tmp2 = N-tmp2;
    while(tmp2>0) {
        ans *= tmp2;
        ans %= MOD;
        tmp2--;
    }
    cout << ans << endl;
    return 0;
}
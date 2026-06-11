#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

ll fnc(bitset<15> bit,vi a,int n,int k){
    ll res = 0;
    rep(i,n) if(bit.test(i)){
        for(int j=0;j<i;j++){
            if(a[i]<=a[j]){
                res += a[j] - a[i] + 1;
                a[i] = a[j] + 1;
            }
        }
    }
    int pre = 0;
    int sum = 0;
    rep(i,n){
        if(pre < a[i]){
            pre = a[i];
            sum++;
        }
    }
    if(sum<k) res = LINF;
    return res;
}

int main(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    rep(i,n) cin >> a[i];
    ll ans = LINF;
    for(int i=0;i<(1<<n);i++){
        bitset<15> bit(i);
        ans = min(ans,fnc(bit,a,n,k));
    }
    cout << ans << endl;
}
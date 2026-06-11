#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// 約数の列挙O(√n)
vector<ll> enum_divisors(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            // 重複しないならばiの相方であるN/iもpush
            if(i!=n/i) res.push_back(n/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

// 桁数を返す
int cnt_digits(ll X){
    int cnt=0;
    while(X>0){
        X/=10;
        cnt++;
    }
    return cnt;
}

int main(){
    ll n;
    cin>>n;
    auto ed=enum_divisors(n);

    int ans=INF;
    for(auto a : ed){
        ll b=n/a;
        int tmp=max(cnt_digits(a),cnt_digits(b));
        ans=min(ans,tmp);
        //cout<<ans<<endl;
    }

    cout<<ans<<endl;
}

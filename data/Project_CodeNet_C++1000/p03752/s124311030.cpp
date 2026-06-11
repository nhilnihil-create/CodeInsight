#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n,k;
    cin>>n>>k;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll ans=INF;

    for (int i=1;i<(1<<n);i++){
        bitset<15> s(i);
        if (s.count()!=k)continue;
        ll ans1=0;
        ll now=0;
        rep(i,n){
            if (s.test(i)){
                if (now<a[i])now=a[i];
                else{
                    now=now+1;
                    ans1+=now-a[i];
                }
            }
            else{
                now=max(now,a[i]);
            }
            
        }
        ans=min(ans,ans1);

    }
    cout<<ans<<endl;


    return 0;
}
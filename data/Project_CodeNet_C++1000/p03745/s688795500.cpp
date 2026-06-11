#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
    int tmp=0;
    int n;cin >>n;
    int ans=1;
    rep(i,n){
        ll a,t;cin >>a;
        if(i==0){
            t=a;
            continue;
        }
        if(tmp==0){
            if(a-t>0)tmp=1;
            if(a-t<0)tmp=2;
        }
        if(tmp==1){
            if(a-t<0){
                tmp=0;
                ans++;
            }
        }
        if(tmp==2){
                if(a-t>0){
                tmp=0;
                ans++;
            }
        }
         t=a;
    }
    cout << ans << endl;
    return 0;
}

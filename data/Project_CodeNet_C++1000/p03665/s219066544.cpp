#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
   int n,p;cin >>n>>p;
   ll odd=0,even=0;
    for (int i = 0; i < n; ++i) {
        int a;cin >>a;
        if(a%2==0){
            even++;
        }
        else {
            odd++;
        }
    }
    if(odd==0&&p==1){
        cout <<0<<endl;
        return 0;
    }
    ll ans=pow(2,n-1);
    if(odd==0){
        ans=pow(2,n);
    }
    cout <<ans<<endl;
}

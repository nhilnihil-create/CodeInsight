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
    ll a,b;cin>>a>>b;
    if(a*b<=0)puts("Zero");
    else {
        if(a>0){
            puts("Positive");
        }
        else {
           if(abs(a-b)%2==1) puts("Positive");
            else puts("Negative");
        }
    }
    return 0;
}

#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
using ll = long long;

ll gcd(ll,ll);
ll lcm(ll,ll);

int main()
{
    ll N,T[110];
    cin>>N;
    rep(i,N){
        cin>>T[i];
    }

    ll ans = 1;
    rep(i,N){
        ans = lcm(T[i],ans);
    }
    cout << ans << endl;

    return 0;
}

ll gcd(ll a, ll b)
{
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a,b);
    return a/g*b;
}
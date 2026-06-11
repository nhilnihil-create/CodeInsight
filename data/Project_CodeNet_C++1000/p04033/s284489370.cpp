#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll a,b; cin>>a>>b;
    if(a*b<=0) cout<<"Zero"<<endl;
    else if(a>0 || (b-a+1)%2==0) cout<<"Positive"<<endl;
    else if(a<0 && (b-a+1)%2!=0) cout<<"Negative"<<endl;
    return 0;
}
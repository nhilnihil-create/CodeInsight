#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll a,b,c,cnt=0; cin>>a>>b>>c;
    while(1){
        if(a%2==1 || b%2==1 || c%2==1) break;
        if(a==b && b==c && c==a){
            cnt=-1;
            break;
        }
        ll x=a,y=b,z=c;
        a = (y+z)/2;
        b = (z+x)/2;
        c = (x+y)/2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
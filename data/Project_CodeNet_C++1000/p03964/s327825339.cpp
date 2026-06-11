#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e5+100;
typedef pair<int,int>pa;
map<pa,int>mp;
ll ans[10];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    ll x,y;
    cin>>x>>y;
    for(int i=2;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        ll p=max((x/a+(x%a!=0)),(y/b+(y%b!=0)));
        x=a*p,y=b*p;
     //   cout<<x<<" "<<y<<endl;
    }
    cout<<x+y<<endl;
    return 0;
}

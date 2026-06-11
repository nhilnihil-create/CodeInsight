#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    string s;
    ll k;
    cin>>s;
    cin>>k;
    string ans;
    for(auto v:s)
    {
        if(v=='a')
        {
            ans+='a';
            continue;
        }
        //cout<<'z'-v<<endl;
        if('z'-v<k)
        {
            k-=('z'-v+1);
            ans+='a';
            continue;
        }
        ans+=v;
    }
    k%=26;
    ans.back()+=k;
    if(ans.back()>'z')ans.back()-=26;
    cout<<ans<<endl;
}

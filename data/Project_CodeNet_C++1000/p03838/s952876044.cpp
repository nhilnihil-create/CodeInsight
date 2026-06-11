#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#include<iomanip>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<double,double>P;

int main()
{
    ll x,y;
    cin>>x>>y;
    ll ans=0;
   
    if(x<y)
    {
        ans=min(abs(y-x),abs(y-abs(x))+1);
    }
    else
    {
        ans=min(abs(y-x)+2,abs(x+y)+1);
    }
    
    cout<<ans;
    
    
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  optimize   ios::sync_with_stdio(0); cin.tie(0);
#define PI  acos(-1.0)
#define RESET(a, b) memset(a, b, sizeof(a))
#define pb push_back
int main()
{
     optimize
     ll n,k,x,y,ans=0;
     cin>>n>>k>>x>>y;
     if(n>=k){
        ans+=k*x;
        ans+=(n-k)*y;
        cout<<ans<<endl;
     }
     else{
        cout<<n*x<<endl;
     }
}

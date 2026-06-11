#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
char s[5][100];
int main()
{
   ios::sync_with_stdio(0);cin.tie(0);
   int n;

   cin>>n>>s[1]+1>>s[2]+1;
   if(n==1) {
    cout<<3<<endl;
    return 0;
   }
   ll ans=0,l;
   int f;
   if(s[1][1]!=s[1][2])
      ans=3,l=2,f=1;
   else ans=6,l=3,f=2;

   for(int i=l;i<=n;i++){
     if(s[1][i]!=s[1][i+1]){
        if(f==1) ans=ans*2%mod;
        else f=1;
     }
     else {
        if(f==1) ans=ans*2%mod,f=2,i++;
        else ans=ans*3%mod,i++;
     }
   }
   cout<<ans<<endl;
   return 0;
}


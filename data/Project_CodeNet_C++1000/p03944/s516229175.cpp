#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
   int w,h,n;
   cin>>w>>h>>n;
   int l=0,r=w,u=h,d=0;
   rep(i,n){
       int x,y,a;
       cin>>x>>y>>a;

       if(a==1) l=max(l,x);
       else if(a==2) r=min(r,x);
       else if(a==3) d=max(d,y);
       else u=min(u,y);
   }

   if(r<=l || u<=d){
       cout<<0<<endl;
       return 0;
   }

   int ans=(r-l)*(u-d);
   //cout<<l<<" "<<r<<" "<<d<<" "<<u<<endl;
   cout<<ans<<endl;
}
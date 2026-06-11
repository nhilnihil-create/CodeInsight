#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int w,h,n;
   cin >> w >> h >>n ;
   VI x(n);
   VI y(n);
   VI a(n);
   rep(i,n){
      cin >> x[i] >> y[i] >> a[i];
   }
   int mxx,mnx,mxy,mny;
   mnx=w;
   mxx=0;
   mny=h;
   mxy=0;
   rep(i,n){
      if(a[i]==1){
         mxx=max(x[i],mxx);
      }
      else if(a[i]==2){
         mnx=min(x[i],mnx);
      }
      else if(a[i]==3){
         mxy=max(y[i],mxy);
      }
      else if(a[i]==4){
         mny=min(y[i],mny);
      } 
   }
   int ans;
   if(mxx>=mnx || mxy>=mny)ans=0;
   else{
      ans=(mnx-mxx)*(mny-mxy);
   }
   cout << ans << endl;
}

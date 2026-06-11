#include <bits/stdc++.h>
#define ll long long 
using namespace std;




int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll w,h,n; 
 cin>>w>>h>>n;
 ll xa,xb,ya,yb;
 xa=0,xb=w,ya=0,yb=h;

 while(cin>>w>>h>>n){
  if(n==1) xa=max(w,xa);
 if(n==2) xb=min(w,xb);
 if(n==3) ya=max(h,ya);
 if(n==4) yb=min(h,yb);
 }
 ll mb,mo;
 if(xb-xa>0) mb=xb-xa;
 else mb=0;
 if(yb-ya>0) mo=yb-ya;
 else mo=0;
 
 cout<<mb*mo<<endl;

 return 0;
}

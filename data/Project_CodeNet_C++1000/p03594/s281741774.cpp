#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int h,w,d;
  cin>>h>>w>>d;
  vector<string> ans(h,string(w,'#'));
  auto draw=[&](Int u,Int v,char c){
    if((u+v+10000)&1) return;
    //cout<<u<<" "<<v<<":"<<c<<endl;
    Int x=(u+v)/2,y=(u-v)/2;
    if(0<=x&&x<w&&0<=y&&y<h) ans[y][x]=c;
  };
  string B="RYGB";
  Int x=0;
   for(Int i=0;i<=h+w;i+=d){
     Int p=x<<1;
     x=!x;
     for(Int j=-h;j<=w;j+=d){
       for(Int a=0;a<d;a++)
	 for(Int b=0;b<d;b++)
	   draw(i+a,j+b,B[p%4]);
       p++;
     }
  }
  
  for(Int i=0;i<h;i++) cout<<ans[i]<<endl;
  return 0;
}

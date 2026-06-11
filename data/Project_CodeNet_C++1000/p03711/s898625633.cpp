#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int x,y;
   cin>>x>>y;
   vector<int>t={1,3,5,7,8,10,12};
   vector<int>k={4,6,9,11};
   int h=2;
   if(x==2&&y==2){cout<<"Yes"<<endl;return 0;}

   bool xx=false;bool yy=false;
   for(int a:t){
      if(x==a){xx=true;}
      if(y==a){yy=true;}
   }
   if(xx&&yy){cout<<"Yes"<<endl;return 0;}
  
   xx=false; yy=false;
   for(int c:k){
      if(x==c){xx=true;}
      if(y==c){yy=true;}
   }
   if(xx&&yy){cout<<"Yes"<<endl;return 0;}

   cout<<"No"<<endl;
return 0;}
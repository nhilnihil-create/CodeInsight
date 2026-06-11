#include <bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;


int main(){

 int n,x,free=0;
  cin>>n;
 set<int>s;

 for(int i=0;i<n;i++)
 {
   cin>>x;

   if(x >=3200) free++;
   else if(x<3200){
    for(int j=0;j<8;j++){
        if(400*j <= x && x<400*(j+1) )
         s.insert(j); }
   }

 }


  if(s.size() == 0 && free >= 1)
   cout<<"1"<<" ";
  else cout<<s.size()<<" ";

   cout<<s.size()+free<<endl;


return 0;
}










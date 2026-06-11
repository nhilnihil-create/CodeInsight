#include <bits/stdc++.h>
using namespace std;

int main() {
  long long H,W,N;
  cin >>H>>W;
  long long Sa,Sb,Sc,ans;
  ans=100000000;
 for(int i=1;i<H;i++){
   Sa=i*W;
   Sb=(H-i)*(W/2);
   Sc=(H-i)*(W-(W/2));
   ans=min(ans,abs(max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc))));
 }
   for(int i=1;i<H;i++){
   Sa=i*W;
   Sb=((H-i)/2)*W;
   Sc=(H-i-(H-i)/2)*W;
   ans=min(ans,abs(max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc))));
 }
   for(int i=1;i<W;i++){
   Sa=i*H;
   Sb=(W-i)*(H/2);
   Sc=(W-i)*(H-(H/2));
   ans=min(ans,abs(max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc))));
 }
     for(int i=1;i<W;i++){
   Sa=i*H;
   Sb=((W-i)/2)*H;
   Sc=(W-i-(W-i)/2)*H;
   ans=min(ans,abs(max(Sa,max(Sb,Sc))-min(Sa,min(Sb,Sc))));
 }
  cout<<ans<<endl;
}

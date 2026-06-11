#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t H,W;
  cin>>H>>W;
  int64_t ans=100000000000;
  for(int i=0;i<=H;i++){
  int64_t a=W*i;int64_t b=((H-i)/2)*W;
    int64_t c=(H-i-((H-i)/2))*W;
    int64_t A=max(a,max(b,c));
    int64_t B=min(a,min(b,c));
    if(A-B<=ans)ans=A-B;
    int64_t d=(W/2)*(H-i);
    int64_t e=(W-(W/2))*(H-i);
    A=max(a,max(d,e));
    B=min(a,min(d,e));
    if(A-B<=ans)ans=A-B;
   }swap(H,W);
  for(int i=0;i<=H;i++){
  int64_t a=W*i;int64_t b=((H-i)/2)*W;
    int64_t c=(H-i-((H-i)/2))*W;
    int64_t A=max(a,max(b,c));
    int64_t B=min(a,min(b,c));
    if(A-B<=ans)ans=A-B;
    int64_t d=(W/2)*(H-i);
    int64_t e=(W-(W/2))*(H-i);
    A=max(a,max(d,e));
    B=min(a,min(d,e));
    if(A-B<=ans)ans=A-B;
   }cout<<ans<<endl;
  return 0;
}
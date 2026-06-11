#include<bits/stdc++.h>
using namespace std;
int main(){
  long H,W;cin>>H>>W;
  vector<long>C(26,0);
  for(long i=0;i<H;i++){
    string s;cin>>s;
    for(char c:s)C[c-97]++;
  }
  long x=0,y=0;
  for(long c:C){
    if(c%2)x++;
    else if(c%4==2)y++;
  }
  if(H%2 && W%2)cout<<(x==1&&y*2<=H+W-2?"Yes":"No");
  else if(H%2)cout<<(x==0&&y*2<=W?"Yes":"No");
  else if(W%2)cout<<(x==0&&y*2<=H?"Yes":"No");
  else cout<<(x==0&&y==0?"Yes":"No");
}
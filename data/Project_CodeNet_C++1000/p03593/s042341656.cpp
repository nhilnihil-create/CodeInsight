#include <bits/stdc++.h>
using namespace std;


int main() {
  int H,W;
  cin>>H>>W;
  vector<long> a(26);
  for(int i=0;i<H;i++) for(int j=0;j<W;j++){
    char c;
    cin>>c;
    a[c-'a']++;
  }
  int req4=(H/2)*(W/2);
  int req1=H%2*W%2;
  int req2=(H*W-req1-req4*4)/2;

  //cout<<req4<<endl;
  //cout<<req2<<endl;
  //cout<<req1<<endl;
  int a4=0,a2=0,a1=0;
  for(int i=0;i<26;i++){
    //cout<<a[i]<<endl;
    a4+=a[i]/4;
    a[i]%=4;
    a2+=a[i]/2;
    a[i]%=2;
    a1+=a[i];
  }
  //cout<<a4<<a2<<a1<<endl;
  if(req4>a4){
    cout<<"No"<<endl;
    return 0;
  }
  a4-=req4;
  a2+=a4*2;
  if(req2>a2){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;

}

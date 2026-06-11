#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int kotae=0;
  vector<int> iro(9,0);
  for(int i=0;i<n;i++){
    if(a[i]<400){
      iro[0]=1;
    }else if(a[i]<800){
      iro[1]=1;
    }else if(a[i]<1200){
      iro[2]=1;
    }else if(a[i]<1600){
      iro[3]=1;
    }else if(a[i]<2000){
      iro[4]=1;
    }else if(a[i]<2400){
      iro[5]=1;
    }else if(a[i]<2800){
      iro[6]=1;
    }else if(a[i]<3200){
       iro[7]=1;
    }else {
      iro[8]++;
    }
  }
  for(int i=0;i<8;i++){
    kotae+=iro[i];
  }
  int saidai=kotae+iro[8];
  if(kotae==0&&iro[8]!=0){
    kotae=1;
  }
  cout<<kotae<<" "<<saidai<<endl;
}

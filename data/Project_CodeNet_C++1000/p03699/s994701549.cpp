#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  int kotae=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    kotae+=a[i];
  }
  sort(a.begin(),a.end());
  int x=kotae;
  bool hantei=false;
  if(x%10==0){
    hantei=true;
    for(int i=0;i<n;i++){
      if(a[i]%10!=0)x-=a[i];
      if(x%10!=0)break;
    }
  }
  if(hantei){
    if(kotae==x){
      cout<<0<<endl;
    }else{
      cout<<x<<endl;
    }
  }else{
    cout<<kotae<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int k;
  cin>>k;
  cout<<50<<endl;
  int a=k/50;
  for(int i=0;i<50;i++){
    if(i)cout<<" ";
    if(i>=(k%50))cout<<a+i-(k%50);
    else cout<<a+i-(k%50)+1+50;
  }
  cout<<endl;
  return 0;
}

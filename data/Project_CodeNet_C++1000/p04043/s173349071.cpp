#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  vector<int>vec(3);
  vec[0]=a;vec[1]=b;vec[2]=c;
  
  int cnt=0,k=0;
  for(int i=0;i<3;i++){
  if(vec[i]==5)cnt++;
    if(vec[i]==7)k++;
    
  }
  if(cnt==2 && k==1)cout<<"YES";
  else cout<<"NO";
}

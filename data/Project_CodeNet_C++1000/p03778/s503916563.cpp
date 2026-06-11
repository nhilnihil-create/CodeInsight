#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll W,a,b;
  cin>>W>>a>>b;
if(abs(b-a)<=W) {
cout<<0<<endl;
return 0;
}
  if(a<b) {
cout<<b-a-W<<endl;
  }
  else {
cout<<a-b-W<<endl;
  }
}

  
  
  
  

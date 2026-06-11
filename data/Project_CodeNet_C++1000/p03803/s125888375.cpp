#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll A,B;
  cin>>A>>B;
  if(A==B) {
cout<<"Draw"<<endl;
  }
  else if(A==1) {
cout<<"Alice"<<endl;
  }
  else if(B==1) {
cout<<"Bob"<<endl;
  }
  else if(A>B) {
cout<<"Alice"<<endl;
  }
  else {
cout<<"Bob"<<endl;
  }
}
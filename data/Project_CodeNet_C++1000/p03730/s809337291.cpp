#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(__gcd(B,C)%__gcd(A,B)==0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}

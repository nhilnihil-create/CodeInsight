#include <bits/stdc++.h>
using namespace std;

int main(){
  long A,B,X;cin>>A>>B>>X;
  long ans;
  if(A==0) ans=B/X+1;
  else ans=B/X-(A-1)/X;
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  string op;
  int B;
  int ans;
  cin>>A>>op>>B;
  if(op=="+"){
    ans=A+B;
  }
  if(op=="-"){
    ans=A-B;
  }
  cout<<ans<<endl;
}

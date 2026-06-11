#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  char op;
  cin>>A>>op>>B;
  int ans;
  if(op=='+'){
    ans = A+B;
  }
  else{
    ans = A-B;
  }
  cout<<ans<<endl;
}
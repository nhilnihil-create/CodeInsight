#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A%2==0 || B%2==0 || C%2==0)puts("0");
  else cout<<min({A*B,B*C,C*A})<<endl;
}
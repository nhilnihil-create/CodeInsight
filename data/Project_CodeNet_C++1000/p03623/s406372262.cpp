#include <bits/stdc++.h>
using namespace std;

int main() {
 int x,a,b;
  cin>>x>>a>>b;
  int A=abs(a-x);
  int B=abs(b-x);
  if(A>B) cout<<'B'<<endl;
  else cout<<'A'<<endl;
}
    
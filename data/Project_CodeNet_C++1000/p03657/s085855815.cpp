#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  string S;
  cin>>A>>B;
  if(A%3==0||B%3==0||(A+B)%3==0) S="Possible";
  else S="Impossible";
  
  cout<<S<<endl;
}
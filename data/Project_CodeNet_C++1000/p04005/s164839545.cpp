#include <bits/stdc++.h>
using namespace std;
int main(){
 int64_t A,B,C;
 cin>>A>>B>>C;
 if(A%2==0||B%2==0||C%2==0){cout<<0<<endl;}
 else {cout<<min(A*B,min(A*C,B*C))<<endl;}
  return 0;
}
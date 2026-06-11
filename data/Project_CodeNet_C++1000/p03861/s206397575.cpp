#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,x;
  cin>>a>>b>>x;
  long long kotae=b/x-a/x;
  if(a%x==0)kotae++;
  cout<<kotae<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,a,b;
  cin>>n>>a>>b;
  long long kotae=max((n-2)*b-(n-2)*a+1,0LL);
  cout<<kotae<<endl;
}
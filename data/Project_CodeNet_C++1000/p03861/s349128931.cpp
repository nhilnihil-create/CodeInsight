#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll a,b,x;
  cin>>a>>b>>x;
  if (x==1) {
    cout<<(b-a+1)<<endl;
    return 0;
  }

  ll res = b/x - (a-1)/x;
  if (a==0) res++;
  cout<<res;
  
  return 0;
}

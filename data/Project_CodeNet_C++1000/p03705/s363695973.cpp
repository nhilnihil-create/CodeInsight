#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,A,B; cin>>N>>A>>B;
  if(N==1) 
  {
    if(A==B) {cout<<1<<endl; return 0;}
    cout<<0<<endl; 
    return 0;
  }
  if(A>B) {cout<<0<<endl; return 0;}
  cout<<(B-A)*(N-2)+1<<endl;
  return 0;
}

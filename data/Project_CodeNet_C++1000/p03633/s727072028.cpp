#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
unsigned long long gcd(unsigned long long a,unsigned long long b){
  while(b!=0){
    
    long long r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main(){
  long long n;
  cin >> n;
  vector<long long> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  unsigned long long ans=a.at(0);
  rep(i,n){
    ans=ans/gcd(ans,a.at(i))*a.at(i);
  }
  cout << ans;
}
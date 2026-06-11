#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MOD = 1000000007;
const int MOD1 = 998244353;
ll gcd(ll x, ll y){
  if(y==0)return x;
  else return gcd(y,x%y);
}
int main() {
  int a,b;
  cin >> a>>b;
  if((a+b)>=10){
    cout << "error"<<endl;
    return 0;
  }
  cout << a+b << endl;
}
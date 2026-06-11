#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;

long long fact(int x){//x! 階乗
  long long ans=1;
  for (int i=1;i<=x;i++){
    ans *= i;
    if(ans>mod)ans%=mod;
  }
  return ans;
}
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int i;
  int n;
  cin>>n;
  i=1;
  cout<<fact(n);
}
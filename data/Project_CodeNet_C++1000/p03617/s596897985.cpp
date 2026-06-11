#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//s[i]-'0'でchar文字→int数に;
//string s = to_string(int数);
//int n = stoi(string文字列)
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  ll a,b,c,d,e;
  cin >> a>>b>>c>>d>>e;
  
  ll ans;
  if(min(min(8*a,4*b),min(2*c,d))==8*a) ans=4*a*e;
  else if(min(min(8*a,4*b),min(2*c,d))==4*b) ans=2*b*e;
  else if(min(min(8*a,4*b),min(2*c,d))==2*c) ans=c*e;
  else if(e%2==0) ans=(e/2)*d;
  else if(min(min(4*a,2*b),c)==4*a) ans=(e/2)*d+4*a;
  else if(min(min(4*a,2*b),c)==2*b) ans=(e/2)*d+2*b;    
  else if(min(min(4*a,2*b),c)==c) ans=(e/2)*d+c;  
  
  cout << ans << endl;
}

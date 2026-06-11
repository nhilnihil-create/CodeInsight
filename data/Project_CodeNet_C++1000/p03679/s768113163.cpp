#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reprl(i, n) for(ll i = n; i >= 0; i--)
#define fori(i, m, n) for(int i = m; i < (int)n; i++)
#define forl(i, m, n) for(ll i = m; i < (ll)n; i++)
#define all(v) v.begin(), v.end()
ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
const string yesno(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  int x,a,b;cin>>x>>a>>b;
  int c=b-a;
  string ans;
  if(c<=0){
    ans="delicious";
  }else if(c<=x){
    ans="safe";
  }else{
    ans="dangerous";
  }
  cout<<ans<<endl;
  return 0;
}

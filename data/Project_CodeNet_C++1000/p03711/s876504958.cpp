#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define repr(i, n) for(int i = n; i >= 0; i--)
#define reprl(i, n) for(ll i = n; i >= 0; i--)
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
const string outputYesNo(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  int x,y;cin>>x>>y;
  map<int,int> m;
  m[1]=0;
  m[2]=2;
  m[3]=0;
  m[4]=1;
  m[5]=0;
  m[6]=1;
  m[7]=0;
  m[8]=0;
  m[9]=1;
  m[10]=0;
  m[11]=1;
  m[12]=0;
  cout<<outputYesNo(m[x]==m[y])<<endl;
  return 0;
}

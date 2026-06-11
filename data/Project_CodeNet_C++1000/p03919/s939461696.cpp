#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll gcd(ll a,ll b){
  if (a%b==0) return(b);
  else return(gcd(b,a%b));
}
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

int main(){
  int H,W;
  cin >> H >> W;
  rep(i,H)rep(j,W){
    string S;
    cin >> S;
    if(S=="snuke") cout << (char)('A'+j) << i+1 << endl;
  }
  return 0;
}
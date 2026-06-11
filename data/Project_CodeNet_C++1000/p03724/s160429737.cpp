#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll gcd(ll a, ll b){
  if(b==0) return a;
  else gcd(b,a%b);
}
ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>vec(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    vec[a]++;
    vec[b]++;
  }
  int ans=0;
  rep(i,n)if(vec[i]%2!=0)ans++;
  if(ans)cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}

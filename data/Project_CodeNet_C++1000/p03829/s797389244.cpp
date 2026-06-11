#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  long n,a,b;
  cin >> n >> a >> b;
  vector<long> x(n);
  rep(i,n) cin >> x.at(i);
  vector<long> dis(n-1);
  rep(i,n-1){
    dis.at(i) = x.at(i+1)-x.at(i);
  }
  long ans = 0;
  rep(i,n-1){
    if(dis.at(i)*a > b) ans += b;
    else ans += dis.at(i)*a;
  }
  cout << ans << endl;
}

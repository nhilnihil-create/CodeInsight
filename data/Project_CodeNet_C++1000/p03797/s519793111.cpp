#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  ll n,m;
  cin >> n >> m;
  ll ans = 0;
  if(n*2 <= m){
    ans += n;
    m -= n*2;
  }
  else{
    ans += m/2;
    m %= 2;
  }
  if(m >= 4){
    ans += m/4;
  }
  cout << ans << endl;
}
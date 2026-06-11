#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
#define rep2(i, n, m) for(int i=n; i<=m; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
const ll inf=1LL << 60;
const ll MOD=1000000007;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int a[n+1];
  rep1(i, n)cin >> a[i];

  int b=1, cnt=0;
  while(b!=2){
    b=a[b];
    cnt++;
    if(cnt==n){
      if(b!=2)cnt++;
      break;
    }
  }

  cout << (cnt<=n ? cnt : -1) << endl;

  return 0;
}
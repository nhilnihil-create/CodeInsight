#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
#define reprange(i, a) for(int i : vector<int>a)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
const ll inf=1LL << 60;
const ll mod=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int ans=min(b, d)-max(a, c);
  cout << (ans>0 ? ans : 0) << endl;

  return 0;
}
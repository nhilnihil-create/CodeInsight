#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

int main() {
  ll n;cin >> n;
  ll bottom_rank = 1LL;
  ll bottom_point = 0LL;
  for(ll i=0LL; i<n;++i){
    ll a,b;cin >>a>>b;
    if(a>=bottom_rank) {
      bottom_rank = a;
      bottom_point = b;
    }
  }
  cout << bottom_rank + bottom_point << endl;
  return 0;
}

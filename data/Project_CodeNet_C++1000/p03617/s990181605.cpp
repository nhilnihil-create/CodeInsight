#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int64_t q,h,s,d,n;
  cin >> q >> h >> s >> d >> n;
  int64_t ans = 0;
  ans += (n/2)*min(min(q*8,h*4),min(s*2,d));
  ans += (n%2)*min(min(q*4,h*2),s);
  cout << ans << endl;
}
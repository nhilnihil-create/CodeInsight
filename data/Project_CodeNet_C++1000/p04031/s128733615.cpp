#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define INF 1<<29 //使いやすい無限


int main(){
  int N;cin>>N;
  vi a(N);
  for(int i=0; i<N; i++){
    cin>>a[i];
  }
  ll ans = INF;
  int cmin = vmin(a);
  int cmax = vmax(a);
  for(int c=cmin; c<=cmax; c++){
    ll buf = 0;
    for(int i=0; i<N; i++){
      buf += (a[i]-c)*(a[i]-c);
    }
    ans = min(ans, buf);
  }
  cout<<ans<<endl;
}
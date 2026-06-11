#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


ll N;

int main(){
  cin >> N;
  ll sN = 2 * N, tN = 3 * N;
  vector<ll> a(tN);
  vector<ll> res(N+1, 0);
  priority_queue<ll, vector<ll>, greater<ll> > fir;
  priority_queue<ll> sec;
  
  for(int i = 0; i < tN; i++){
    cin >> a[i];
  }
  
  for(int i = 0; i < N; i++){
    fir.push(a[i]);
    res[0] += a[i];
  }

  for(int i = 0; i < N; i++){
    int mi = fir.top();
    int nex = a[N + i];
    res[i + 1] = res[i];
    if(mi < nex) {
      fir.pop();
      fir.push(nex);
      res[i+1] += nex - mi;
    }
   //cout << i+1 << ' ' << sub[i+1] << endl;
  }
  
  ll sub = 0;
  for(int i = sN; i < tN; i++){
    sec.push(a[i]);
    sub += a[i];
  }
  res[N] -= sub;
  
  for(int i = 0; i < N; i++){
    int ma = sec.top();
    int nex = a[sN - 1 - i];
    
    if(ma > nex) {
      sec.pop();
      sec.push(nex);
      sub += nex - ma;
    }
    res[N - 1 - i] -= sub;
  }
  
  ll ans = (ll)-1e18;
  for(int i = 0; i <= N; i++){
   ans = max(ans, res[i]);
  }
  
  cout << ans;
  
  return 0;
}
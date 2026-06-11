#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(ll i=f; i<(n); i++)
int main()
{
  ll ans = -1;
  ll n, k;
  cin >> n >> k;
  vector<ll> a;
  REP(i,0,n){
    ll ins;
    cin >> ins;
    a.push_back(ins);
  }

  REP(i,0,1<<n){
    ll cnt = 0, ue = 0;
    ll mae = a[0]-1;
    REP(j,0,n){
      ll ima = a[j];
      if((i>>j) & 1){
        ue++;
        if(mae>=ima){
          mae++;
          cnt += mae - ima;
        }
      }
      //cout << ima << " ";
      mae = max(mae, ima);
    }
    //cout << ": " << ue <<endl;
    if(ue>=k){
      if(ans==-1)ans = cnt;
      ans = min(ans, cnt);
    }
  }

  cout << ans << endl;
  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper; cin >> end_stoper;

  return 0;
}
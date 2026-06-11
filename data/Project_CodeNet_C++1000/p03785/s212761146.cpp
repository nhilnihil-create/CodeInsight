#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int n;
  ll c,k;
  cin >> n >> c >> k;
  vector<ll> t(n);
  for(int i=0;i<n;i++) cin >> t[i];

  sort(t.begin(),t.end());

  ll cnt = 0;
  ll ans = 1;
  ll bus = t[0] + k;
  for(int i=0;i<n;i++){
    if(t[i] <= bus && cnt < c){
      cnt++;
    }else if(t[i] <= bus && cnt >= c){
      ans++;
      cnt = 1;
      bus = t[i] + k;
    }else if(t[i] > bus){
      ans++;
      cnt = 1;
      bus = t[i] + k;
    }
  }


  cout << ans << endl;
}

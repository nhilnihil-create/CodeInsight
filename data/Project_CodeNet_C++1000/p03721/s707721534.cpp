#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  ll n, k;
  cin >> n >> k;
  ll cnt[100005] = {};
  for(int i=0; i<n; i++){
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    cnt[ai] += bi;
  }
  ll s=0;
  for(int i=0; i<100005; i++){
    s += cnt[i];
    if(s >= k){
      cout << i+1 << endl;
      return 0;
    }
  }
  return 0;
}

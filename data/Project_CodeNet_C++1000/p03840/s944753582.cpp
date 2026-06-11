#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[7];
ll solve0(){
  ll ans=0,tmp;
  ans += a[1];
  ans += (a[0]/2)*2;
  ans += (a[3]/2)*2;
  ans += (a[4]/2)*2;
  return ans;
}
ll solve1(){
  ll ans=0,tmp;
  if(a[0]>=1&&a[3]>=1&&a[4]>=1){
    ans += 3;
    a[0]--;
    a[3]--;
    a[4]--;
  }
  ans += a[1];
  ans += (a[0]/2)*2;
  ans += (a[3]/2)*2;
  ans += (a[4]/2)*2;
  return ans;
}
signed main(){
  for(int i=0;i<7;i++){
    cin >> a[i];
  }
  cout << max(solve1(),solve0()) << endl;
}

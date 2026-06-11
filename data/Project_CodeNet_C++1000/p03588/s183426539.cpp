#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 510000;
const double pi=acos(-1);

int main(){
  int n;
  cin >> n;
  vector<pair<ll,ll>>vec;
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    vec.push_back(make_pair(a,b));
  }
  sort(vec.begin(),vec.end(),greater<pair<ll,ll>>());
  cout << vec[0].first+vec[0].second << endl;
  return 0;
}

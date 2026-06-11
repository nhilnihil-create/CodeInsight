#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
using pll = pair<long,long>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

vector<pll> btn(100010);

int main() {
  int n; cin>>n;
  ll cnt=0;
  rep(i,n) cin>>btn[i].first>>btn[i].second;
  for(int i=n-1;i>=0;i--) {
    btn[i].first+=cnt;
    ll q=btn[i].first%btn[i].second;
    if(q!=0) cnt+=btn[i].second-q;
  }
  cout<<cnt<<endl;
}

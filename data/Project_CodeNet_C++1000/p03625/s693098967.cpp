#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n){
    int x;
    cin >> x;
    mp[x]++;
  }
  vector<pair<ll,ll>> m;
  for(auto p : mp){
    if(p.second >= 2){
      m.push_back(make_pair(p.first,p.second));
    }
  }
  if(m.size() == 0){
    cout << 0 << endl;
    return 0;
  }
  sort(m);
  reverse(m);
  if(m[0].second >= 4){
    cout << m[0].first * m[0].first << endl;
    return 0;
  }
  cout << m[0].first * m[1].first << endl;
}
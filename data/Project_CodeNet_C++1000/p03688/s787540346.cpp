#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n)cin >> a[i];
  sort(ALL(a));
  vector<P> v;
  v.push_back(make_pair(a[0],1));
  for(int i = 1;i < n;i++){
    if(v.back().first == a[i])v.back().second++;
    else v.push_back(make_pair(a[i],1));
  }
  bool is = true;
  if(v.size() > 2)is = false;
  //if(v.size() == 2)if(v[0].first != 1 || v[1].first != 2 || v[0].second != 1)is = false;
  if(v.size() == 2)if(v[1].second == 1 || v[1].second/2+v[0].second < v[1].first || v[0].second+1 > v[1].first || v[1].first-v[0].first != 1)is = false;
  if(v.size() == 1)if(v[0].first*2 > n && v[0].first != n-1)is = false;
  cout << (is ? "Yes\n" : "No\n");

  


  return 0;
}
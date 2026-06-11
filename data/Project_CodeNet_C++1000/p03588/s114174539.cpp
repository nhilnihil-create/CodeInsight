#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> x;
  for(int i(0);i<N;i++){
    int a,b;
    cin>>a>>b;
    x.push_back({a,b});
  }
  sort(x.begin(),x.end());
  ll sum(0);
  sum += x[0].first;
  sum += x[N-1].first - x[0].first;
  sum += x[N-1].second;
  cout << sum << endl;
  return 0;
}

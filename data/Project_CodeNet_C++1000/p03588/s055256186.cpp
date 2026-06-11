#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll N; cin >> N;
  vector<pair<ll,ll>>  vec(N);
  for(int i = 0; i < N; i++){ cin >> vec[i].first >> vec[i].second;}
  
  sort(vec.rbegin(),vec.rend());

  cout << vec.front().first + vec.front().second << endl; return 0;}
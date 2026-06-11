#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<P> an(n);
  for(int i=0; i<n; ++i){
    cin >> an[i].first;
    an[i].second = i;
  }
  sort(an.begin(),an.end());
  int ans = 0;
  for(int i=0; i<n; ++i){
    int x = an[i].second - i;
    if(x%2 != 0) ++ ans;
  }
  ans /= 2;
  cout << ans << endl;
}
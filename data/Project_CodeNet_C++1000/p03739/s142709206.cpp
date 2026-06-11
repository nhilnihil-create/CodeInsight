#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  ll plusans = 0, cnt = 0;
  for(int i=0; i<n; ++i){
    cnt += an[i];
    if(cnt *(i%2 ? 1:-1) >= 0){
      plusans += abs(cnt) +1;
      cnt = (i%2 ? -1:1);
    }
  }
  ll minusans = 0;
  cnt = 0;
  for(int i=0; i<n; ++i){
    cnt += an[i];
    if(cnt *(i%2 ? -1:1) >= 0){
      minusans += abs(cnt) +1;
      cnt = (i%2 ? 1:-1);
    }
  }
  cout << min(plusans, minusans) << endl;
}
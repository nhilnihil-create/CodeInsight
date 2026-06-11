#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> x(N);
  for(int i=0;i<x.size();i++){
    cin >> x.at(i);
  }
  int ans = 0;
  for(int i=0;i<x.size();i++){
    ans +=  2*min(x.at(i),K-x.at(i));
  }
  cout << ans << endl;
}
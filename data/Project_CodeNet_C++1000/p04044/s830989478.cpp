#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin >> N >> L;
  vector<string> S(N);
  for(auto &x:S)
    cin >> x;
  
  sort(S.begin(),S.end());
  
  for(auto &x:S)
    cout << x;
  cout << endl;
  
  return 0;
  
}
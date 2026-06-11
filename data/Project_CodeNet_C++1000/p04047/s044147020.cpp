#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  vector<int> kushi;
  for(int i = 0; i < 2 * N; i++){
    int a; cin >>a;
    kushi.push_back(a);
  }
  sort(kushi.begin(),kushi.end());
  int ans = 0;
  for(int i = 0; i < 2 * N; i+=2)
    ans += kushi.at(i);
  
  cout << ans << endl;
}
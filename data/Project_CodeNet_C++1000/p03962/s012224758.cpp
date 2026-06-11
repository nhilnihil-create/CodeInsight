#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int N= 3;

  set<int> colors;
  int buf;
  for(int i=0; i<N; i++){
    cin >> buf;
    colors.insert(buf);
  }
  int64_t ans= colors.size();

  cout << ans << endl;
}
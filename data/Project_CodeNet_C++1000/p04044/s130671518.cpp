#include <bits/stdc++.h>
using namespace std;

void solve(){
  int N, L; cin >> N >> L;
  vector<string> wd;
  for(int i = 0; i < N; ++i) {
    string tmp;
    cin >> tmp;
    wd.push_back(tmp);
  }
  sort(wd.begin(), wd.end());
  for( auto word: wd){
    cout << word ;
  }
  cout << endl;
}

int main(){
  solve();
  return 0;
}

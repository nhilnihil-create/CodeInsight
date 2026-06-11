#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N, K;
  cin >> N >> K;
  unordered_set<char> s;
  for(int i = 0; i < K; i++){
    char d;
    cin >> d;
    s.insert(d);
  }
  bool good = true;
  for(int i = 0; i < 1000000; i++){
    good = true;
    string S = to_string(N+i);
    for(int j = 0; j < S.size(); j++){
      if(s.count(S[j])){
        good = false;
        break;
      }
    }
    if(good){
      cout << N + i <<endl;
      return 0;
    }
  }
}

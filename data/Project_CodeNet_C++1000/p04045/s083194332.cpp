#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  
  vector<char> vec(K);
  for (int i = 0; i < K; i++) {
    cin >> vec.at(i);
  }
  
  for (int x = N; x < 100000; x++) {
    int tmp = x;
    string s = to_string(tmp);
    bool flag = true;
    vector<char> pop(s.size());
    
    for (int i = 0; i < s.size(); i++) {
      pop.at(i) = s.at(i);
    }

    for (int i = 0; i < K; i++) {
      if(count(pop.begin(), pop.end(), vec.at(i))) {
        flag = false;
      }
    }
    
    if(flag) {
      cout << x << endl;
      break;
    }
  }

}
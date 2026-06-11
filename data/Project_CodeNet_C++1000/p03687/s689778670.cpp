#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int min_ = 100000;
  int N = S.size();
  for (int i = 0; i < 26; i++){
    int count = 0;
    int max_ = 0;
    for (int j = 0; j < N; j++){
      if (S[j] == i + 'a') {
        max_ = max(max_, count);
        count = 0;
      }
      else count++;
    }
    max_ = max(max_, count);
    min_ = min(min_, max_);
  }
  
  cout << min_ << endl;
}
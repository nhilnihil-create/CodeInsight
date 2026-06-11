#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  
  vector<int>count(N,0);
  for (int i = 0; i < N; i++) {
    int A = 0;
    int B = 0;
    int C = 0;
    for (int j = 0; j < N; j++) {
      if (S.at(i) == S.at(j)){
        count.at(i) = max(count.at(i),abs(C-j)-1);
        if (A == 0){
          B = j;
          A++;
        }
        C = j;
      }
      if (j == N-1){
        count.at(i) = max(count.at(i),max(B,N-C-1));
      }
    }
  }
  sort(count.begin(), count.end());
  cout << count.at(0) << endl;
}
          
        
    
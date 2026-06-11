#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, A, B, Entry = 0, Brank = 0;
  bool IsPassed;
  string S;
  cin >> N >> A >> B >> S;
  for(int i = 0; i < N; i++) {
    if(S[i] == 'a') {
      if(Entry < A + B) {
        cout << "Yes" << endl;
        Entry++;
      }
      else {
        cout << "No" << endl;
      }
    }
    else if(S[i] == 'b') {
      if(Entry < A + B && Brank < B) {
        cout << "Yes" << endl;
        Entry++;
        Brank++;
      }
      else {
        cout << "No" << endl;
      }
    }
    else if(S[i] == 'c') {
      cout << "No" << endl;
    }
  }
}
  
  
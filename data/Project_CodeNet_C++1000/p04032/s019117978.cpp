#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  int L = -1;
  int R = -1;
  for (int i = 0; i < N - 1; i++){
    if (s[i] == s[i + 1]){
      L = i + 1;
      R = i + 2;
    }
  }
  for (int i = 0; i < N - 2; i++){
    if (s[i] == s[i + 2]){
      L = i + 1;
      R = i + 3;
    }
  }
  cout << L << ' ' << R << endl;
}
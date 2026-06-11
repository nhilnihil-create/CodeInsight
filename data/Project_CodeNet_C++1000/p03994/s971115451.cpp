#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  int N = s.size();
  for (int i = 0; i < N - 1; i++){
    if (s[i] != 'a' && K >= 'z' + 1 - s[i]){
      K -= 'z' + 1 - s[i];
      s[i] = 'a';
    }
  }
  K %= 26;
  for (int i = 0; i < K; i++){
    if (s[N - 1] == 'z'){
      s[N - 1] = 'a';
    } else {
      s[N - 1]++;
    }
  }
  cout << s << endl;
}
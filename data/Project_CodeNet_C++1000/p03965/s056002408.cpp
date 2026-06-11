#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (i % 2 == 0){
      if (s[i] == 'p'){
        ans--;
      }
    } else {
      if (s[i] == 'g'){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
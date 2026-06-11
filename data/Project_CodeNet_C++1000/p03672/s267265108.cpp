#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;



int main() {
  int ans = 0;
  int i = 0;
  string s;
  cin >> s;
  int n = s.length();
  while(ans == 0){
    int a = n - 2 * (i + 1);
    if (s.substr(0, a) == s.substr(0, a/2) + s.substr(0, a/2)){
      ans = s.substr(0, a).length(); 
    }
    i++;
  }
  cout << ans << endl;
}

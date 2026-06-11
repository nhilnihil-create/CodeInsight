#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;

  while(1){
    if (s.size() >= 7) {
      if (s.substr(s.size()-7) == "dreamer"){
        //cout << s.substr(s.size()-7) << endl;
        s.erase(s.size()-7);
        //cout << s << endl;
        continue;
      }
    }

    if (s.size() >= 6) {
      if (s.substr(s.size()-6) == "eraser"){
        //cout << s.substr(s.size()-6) << endl;
        s.erase(s.size()-6);
        //cout << s << endl;
        continue;
      }
    }

    if (s.size() >= 5) {
      if (s.substr(s.size()-5) == "dream" || s.substr(s.size()-5) == "erase"){
        //cout << s.substr(s.size()-5) << endl;
        s.erase(s.size()-5);
        //cout << s << endl;
        continue;
      }
    }

    break;
  }

  if (s.size() == 0) cout <<"YES" << endl;
  else cout << "NO" << endl;

}
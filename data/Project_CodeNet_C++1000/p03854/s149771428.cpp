#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//dream dreamer erase eraser
int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'r' && s[i+1] == 'e'){
      if(s[i+2] == 's' && s[i+3] == 'a' && s[i+4] == 'r' && s[i+5] == 'e'){
        i += 5;
        continue;
      }
      if(s[i+2] == 'm'&&s[i+3] == 'a'&&s[i+4] == 'e'&&s[i+5] == 'r'&&s[i+6] == 'd'){
        i += 6;
        continue;
      }
      else{
        cout << "NO" <<endl;
        return 0;
      }
    }
    if(s[i] == 'm'&&s[i+1] == 'a'&&s[i+2] == 'e'&&s[i+3] == 'r'&&s[i+4] == 'd'){
      i+=4;
      continue;
    }
    if(s[i] == 'e'&&s[i+1] == 's'&&s[i+2] == 'a'&&s[i+3] == 'r'&&s[i+4] == 'e'){
      i += 4;
      continue;
    }else{
      cout << "NO" <<endl;
      return 0;
    }
  }
  cout << "YES"<<endl;
}
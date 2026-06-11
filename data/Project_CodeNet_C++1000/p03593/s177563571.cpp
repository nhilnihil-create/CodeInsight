#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> str(h);
  for(int i=0; i<h; ++i) cin >> str[i];
  vector<int> cnt(26,0);
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    ++cnt[str[i][j] - 'a'];
  }
  bool ansis = true;
  if(h%2 == 0 && w%2 == 0){
    for(int i=0; i<26; ++i){
      if(cnt[i] %4 !=0) ansis = false;
    }
  }
  else if(h%2 == 1 && w%2 == 1){
    int mod1 = 0, mod2 = 0, mod3 = 0;
    for(int i=0; i<26; ++i){
      if(cnt[i] %4 == 1) ++mod1;
      if(cnt[i] %4 == 2) ++mod2;
      if(cnt[i] %4 == 3) ++mod3;
    }
    if(mod1+mod3 > 1 || mod2+mod3 > (h+w-2)/2) ansis = false;
  }
  else{
    int mod2 = 0;
    for(int i=0; i<26; ++i){
      if(cnt[i] %4 == 1 || cnt[i] %4 == 3) ansis = false;
      if(cnt[i] %4 == 2) ++mod2;
    }
    if(w%2 && mod2 > h/2) ansis = false;
    if(h%2 && mod2 > w/2) ansis = false;
  }
  cout << (ansis? "Yes": "No") << endl;
}
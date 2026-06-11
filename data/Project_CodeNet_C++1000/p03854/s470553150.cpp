#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)




bool check(string s, string dore, int cp) {
  int len_dore = dore.size();

  for(int i = 0; i < len_dore; i++) {
    if(s.at(i + cp) != dore.at(i)) {
      return false;
    }
  }

  return true;
}

int main() {
  string s;
  cin >> s;

  string dream = "dream", dreamer = "dreamer", erase = "erase", eraser = "eraser";
  int len_dream = dream.size(), len_dreamer = dreamer.size(), len_erase = erase.size(), len_eraser = eraser.size();
  int len_s = s.size();

  int current_pos = 0;

  while(1){
    //cout  << ' ' << current_pos << endl;
    if(current_pos == len_s) {
      cout << "YES" << endl;
      return 0;
    }
    else if(current_pos > len_s) {
      break;
    }
    
    if(current_pos + len_eraser <= len_s && check(s,eraser,current_pos)) {
    //  cout << 1 << endl;
      current_pos += len_eraser;
      continue;
    }
    else if(current_pos + len_erase <= len_s && check(s,erase,current_pos)) {
      //cout << 2 << endl;
      current_pos += len_erase;
      continue;
    }
    else if(current_pos + len_dreamer <= len_s && check(s,dreamer,current_pos)) {
    //  cout << 3 << endl;
      current_pos += len_dreamer;
      
      if(current_pos < len_s && s.at(current_pos) != 'd' && s.at(current_pos) != 'e') {
      //  cout << 4 << endl;
        current_pos -= len_dreamer;
        current_pos += len_dream;
      }
      continue;
    }
    else if(current_pos + len_dream <= len_s && check(s,dream,current_pos)) {
      //cout << 5 << endl;
      current_pos += len_dream;
      continue;
    }
    else {
      //cout << 6 << endl;
      break;
    }
  }
  
  cout << "NO" << endl;
}

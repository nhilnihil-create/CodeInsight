#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int h, w; cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; i++){
    cin >> a[i];
  }

  int one = h%2 == 1 && w%2 == 1;
  int two = (h%2 == 1 ? w/2 : 0) + (w%2 == 1 ? h/2 : 0);
  int four = h/2 * (w/2);
  vector<int> cnt(26, 0);
  for(int i = 0; i < h; i++){
    for(char c : a[i]){
      cnt[c - 'a']++;
    }
  }

  for(int i = 0; i < 26; i++){
    while(four > 0 && cnt[i] >= 4){
      four--;
      cnt[i] -= 4;
    }
  }
  for(int i = 0; i < 26; i++){
    while(two > 0 && cnt[i] >= 2){
      two--;
      cnt[i] -= 2;
    }
  }
  for(int i = 0; i < 26; i++){
    if(one > 0 && cnt[i] >= 1){
      one--;
      cnt[i] -= 1;
    }
  }
  cout << (one + two + four == 0 ? "Yes" : "No") << endl;

  return 0;
}

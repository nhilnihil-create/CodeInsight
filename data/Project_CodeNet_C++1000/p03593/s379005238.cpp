#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++){
    cin >> a[i];
  }
  vector<int> cnt(26, 0);
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cnt[a[i][j] - 'a']++;
    }
  }
  if (H % 2 == 0 && W % 2 == 0){
    bool ok = true;
    for (int i = 0; i < 26; i++){
      if (cnt[i] % 4 != 0){
        ok = false;
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (H % 2 == 0 || W % 2 == 0){
    bool ok = true;
    int cnt2 = 0;
    for (int i = 0; i < 26; i++){
      if (cnt[i] % 2 != 0){
        ok = false;
      }
      if (cnt[i] % 4 != 0){
        cnt2++;
      }
    }
    if (!ok){
      cout << "No" << endl;
    } else {
      if (H % 2 == 0){
        if (cnt2 <= H / 2){
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      } else {
        if (cnt2 <= W / 2){
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
  } else {
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 26; i++){
      if (cnt[i] % 2 == 1){
        cnt1++;
      }
      if (cnt[i] % 4 >= 2){
        cnt2++;
      }
    }
    if (cnt1 <= 1 && cnt2 <= H / 2 + W / 2){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
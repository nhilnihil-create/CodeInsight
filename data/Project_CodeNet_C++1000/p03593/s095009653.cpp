#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int H,W;
  cin >> H >> W;
  vector<int> num(26);
  for(int i = 0;i < H;i++) {
    for(int j = 0;j < W;j++) {
      char ch;
      cin >> ch;
      num.at(ch-'a')++;
    }
  }

  bool exist_odd = false;
  for(int i = 0;i < 26;i++) {
    if(exist_odd && num.at(i)%2 != 0) {
      cout << "No" << endl;
      return 0;
    }
    if(num.at(i)% 2 != 0) exist_odd = true;
  }
  
  int sum = 0;
    for(int i = 0;i < 26;i++) {
      sum += num.at(i) / 4;
  }

  if(H%2 == 0 && W%2 == 0) {
    for(int i = 0;i < 26;i++) {
      if(num.at(i)%4 != 0) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }else if(H % 2 == 0 && W % 2 != 0) {
    if(sum*4 < H*(W-1) || exist_odd) cout << "No" << endl;
    else cout << "Yes" << endl;
  }else if(H % 2 != 0 && W % 2 == 0) {
    if(sum*4 < W*(H-1) || exist_odd) cout << "No" << endl;
    else cout << "Yes" << endl;
  }else{
    if(sum*4 < (H-1)*(W-1)) cout << "No" << endl;
    else cout << "Yes" << endl;
  }

}

#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  vector<int> vec(3);
  for (int i = 0; i < 3; i++){
    cin >> vec.at(i);
  }
  if(vec.at(0) % 2 == 1 || vec.at(1) % 2 == 1 || vec.at(2) % 2 == 1){
    cout << 0;
    return 0;
  }
  sort(vec.begin(), vec.end());
  a = vec.at(2) - vec.at(1);
  b = vec.at(1) - vec.at(0);
  int ca = -1, cb = -1, tmp;
  tmp = a;
  if (a != 0){
    ca = 0;
    while(tmp % 2 == 0){
      tmp /= 2;
      ca++;
    }
  }
  tmp = b;
  if (b != 0){
    cb = 0;
    while(tmp % 2 == 0){
      tmp /= 2;
      cb++;
    }
  }
  if(ca == -1) cout << cb;
  else if(cb == -1) cout << ca;
  else cout << min(ca, cb);
  return 0;
}
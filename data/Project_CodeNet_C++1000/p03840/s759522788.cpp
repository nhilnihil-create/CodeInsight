#include <bits/stdc++.h>
using namespace std;
int main () {
  vector<long> data(7);
  for (int i = 0;i < 7; i++){
    cin >> data.at(i);
  }
  vector<int> n{0, 3, 4};
  int count = 0;
  for(int a: n) {
    if (data.at(a) % 2 == 1) count++;
  }
  long sub = 0;
  if(data.at(0) > 0 && data.at(3) > 0 && data.at(4) > 0) {
    if (count > 1) {
      for(int a: n) {
        data.at(a)--;
      }
      sub = 3;
    }
  }
  cout <<(long) sub + (data.at(0) / 2) * 2 + data.at(1) + (data.at(3)/ 2 + data.at(4) / 2) * 2 << endl;
}

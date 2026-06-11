#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> count(100010, 0);
  
  for (int i = 0; i < N; i++){
    int x;
    cin >> x;
    count[x]++;
  }
  
  
  int onecard = 0;   // 1枚しかないカードの枚数 
  int cards_num = 0; // 2枚以上のカードの種類
  for (int i = 1; i <= 100000; i++) {
    if (count[i] == 1) onecard++;
    if (count[i] > 1) cards_num++;
  }
  
  
  if ((cards_num - (N-onecard)) % 2) {
    cout << onecard + cards_num - 1<< endl;
  } else {
    cout << onecard + cards_num << endl;
  }
}
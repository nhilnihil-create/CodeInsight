#include <bits/stdc++.h>
using namespace std;

int main() {
  int num, p;
  int kisuCnt = 0;
  cin >> num >> p;

  for (int i = 0; i < num; i++){
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 1) kisuCnt++;
  }
  
  if(kisuCnt == 0){
    if (p == 0) cout << (1LL << num);
    else cout << 0;
  } else {
    cout << (1LL << num - 1);
  }
}
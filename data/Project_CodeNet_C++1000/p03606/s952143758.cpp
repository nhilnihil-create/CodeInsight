#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N;
  cin >> N;
 
  int startSheet, finishSheet;
  int sumNinzu = 0;
  rep(i, N) {
    cin >> startSheet >> finishSheet;
    
    // 計算
    sumNinzu += finishSheet - startSheet + 1;
  }
  
  cout << sumNinzu;
}
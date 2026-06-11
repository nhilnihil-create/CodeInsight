#include <bits/stdc++.h>
using namespace std;
int main(){
  long long K;
  cin >> K;
  vector<long long> a(50, K / 50 + 49);
  for (int i = 0; i < K % 50; i++){
    for (int j = 0; j < 50; j++){
      if (i == j){
        a[j] += 50;
      } else {
        a[j]--;
      }
    }
  }
  cout << 50 << endl;
  for (int i = 0; i < 50; i++){
    cout << a[i];
    if (i < 49){
      cout << ' ';
    }
  }
  cout << endl;
}
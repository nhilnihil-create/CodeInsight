#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int R = 0;
  cin >> N;

  for(int i = 0; i < N; i++){
    int l, r;
    cin >> l >> r;
    while(l <= r){
      R++;
      l++;
    }
  }
  cout << R << endl;
}
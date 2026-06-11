#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  int l = 0; 
  int r = 0;
  int hito = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
  	cin >> l >> r;
    hito += (r - l) + 1;
  }
    cout << hito << endl;
}

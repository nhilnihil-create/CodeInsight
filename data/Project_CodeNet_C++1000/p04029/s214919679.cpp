#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, need=0;
  cin >> N;
  for (int i=0; i<N ;i++){
    need+=i+1;
  }
  cout << need << endl;
}
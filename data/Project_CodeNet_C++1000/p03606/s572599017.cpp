#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  int p1, p2;
  for(int i = 0; i < N; i++){
    cin >> p1 >> p2;
    sum += (p2-p1+1);
  }
  cout << sum << endl;
}
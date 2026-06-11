#include <bits/stdc++.h>
using namespace std;

int main() {

int N , l , r ;
  cin >> N;
  int s , a = 0;
  for(int i = 0; i < N; i++){
    cin >> l >> r;
    s = r - l + 1;
    a += s;
  }
  cout << a << endl;
}
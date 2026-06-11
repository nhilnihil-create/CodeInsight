#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int y =0;
  cin >> N;
  int x=1;
  while (x < N+1){
    y += x;
    x++;
  }
  cout << y << endl;
}
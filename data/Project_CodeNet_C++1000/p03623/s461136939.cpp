#include<bits/stdc++.h>
using namespace std;

int value(int n){
  if(n < 0)
    n *= -1;
  return n;
}
int main(void){
  int x, a, b;
  int delta_a, delta_b;
  cin >> x >> a >> b;
  delta_a = value(x - a);
  delta_b = value(x - b);
  if(delta_a < delta_b)
    cout << "A" << "\n";
  else
    cout << "B" << "\n";
  return 0;
}

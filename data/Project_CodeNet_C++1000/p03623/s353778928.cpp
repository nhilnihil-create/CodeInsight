#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  
  int dist_a = (x-a)*(x-a);
  int dist_b = (x-b)*(x-b);
  
  if(dist_a < dist_b) cout << "A" << endl;
  else cout << "B" << endl;
}
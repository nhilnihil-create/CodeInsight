#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int goukei=0;
 for (int i = 0; i < N; i++) {
   int x;
   cin >> x;
   if ( K < x)
     goukei += (x-K)*2;
   else if ((K-x) < x)
     goukei += (K-x)*2;
   else
     goukei += x*2;
 }
  cout << goukei << endl;
}
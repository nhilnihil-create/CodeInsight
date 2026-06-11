#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int sum = 0;
  int st,en;
  for (int i = 0; i < N; i++) {
    cin >> st >> en;
    sum+= en-st+1;
  }
   cout << sum << endl; 
}
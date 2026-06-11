#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long power = 1;
  int kaisu = 1;
  while(kaisu <= n){
    power *= kaisu;
    power %= 1000000007;
    kaisu++;
  }
  cout << power << endl;
}

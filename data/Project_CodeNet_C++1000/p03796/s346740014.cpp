#include <bits/stdc++.h>
using namespace std;

long long fact(int k) {
  if (k == 0) {
    return 1;
  }

  // sum関数の中でsum関数を呼び出している
  long long f = fact(k - 1);
  return (f * k)%1000000007;
}

int main() {
	int n;
  cin >> n;
  
 cout << fact(n) << endl;




}

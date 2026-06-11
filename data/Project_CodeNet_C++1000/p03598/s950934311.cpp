#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, x;
  cin >> N >> K;
  int sum = 0 ;
    for (int i = 0; i < N; i++){
      cin >> x;
      if ( 2 * x <= K)
        sum += 2 * x;
      else 
    	sum += 2 * K - 2 * x;
    }
	cout << sum << endl;
}


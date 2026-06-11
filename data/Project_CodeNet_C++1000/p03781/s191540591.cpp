#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;


long long X;
int main() {
  while (cin >> X) {
	long long lo = 0, hi = 1LL<<30;
	while (hi - lo > 1) {
	  long long mid = (hi + lo) / 2;
	  
	  long long sum = mid * (mid + 1) / 2;
	  if (sum >= X) hi = mid;
	  else lo = mid;
	}
	cout << hi << endl;
  }
}




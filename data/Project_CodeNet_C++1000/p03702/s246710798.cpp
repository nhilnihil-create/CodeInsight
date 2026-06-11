#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long A, B;
long long H[210000];
 
int main() {
 
  cin >> N >> A >> B;
  
	for (int i = 0; i < N; ++i) 
      cin >> H[i];
  
	sort(H, H+N);
  
	long long lo = 0, hi = 1LL<<30;
  
	while (hi - lo > 1) {
	  long long mid = (lo + hi) / 2;
	  long long need = 0;
      
	  for (int i = 0; i < N; ++i) {
		long long rem = H[i] - mid * B;
        
		if (rem > 0) need += (rem + (A-B-1)) / (A-B);
	  }
      
	  if (need <= mid) hi = mid;
	  else lo = mid;
	}
	cout << hi << endl;
  }


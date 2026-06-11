#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  	ll N;
  	cin >> N;
  	
	map<ll,int> A;
  	for (ll i=0; i<N; ++i) {
		ll llbuff;
		cin >> llbuff;
      	A[llbuff]++;
        if (A[llbuff]%2) A[llbuff]=1;
        else A.erase(llbuff);
    }
  
  	cout << A.size() << endl;

  	return 0;
}
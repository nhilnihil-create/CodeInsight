#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N, K;
	cin >> N >> K;
	int x[N];
	rep(i,N) cin >> x[i];
	
	int dist = 0;
	rep(i,N){
		dist += 2*min(x[i], K- x[i]);
	}
	cout << dist << endl;

	return 0;
}

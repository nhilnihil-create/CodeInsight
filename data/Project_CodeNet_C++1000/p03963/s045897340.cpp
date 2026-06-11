#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, K;
	cin >> N >> K;

	LL ans = K;
	rep(i,N-1) ans *= K - 1;
	cout << ans << endl;
	
}











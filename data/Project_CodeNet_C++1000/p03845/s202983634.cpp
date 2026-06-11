#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<int> T(N);
	int res = 0;
	rep(i,N){
		cin >> T[i];
		res += T[i];
	}
	int M;cin >> M;
	rep(i,M){
		int P, X;cin >> P >> X;
		int ans = res - T[P-1] + X;
		cout << ans << endl;
	}
	return 0;

}











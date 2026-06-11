#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

LL comb(LL n, LL k){
	LL res=1;
	for(LL i=0; i<k; i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

int main(){
	int N, P;
	cin >> N >> P;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	LL ans=0, odd=0;
	rep(i,N) if(A[i]%2) odd++;
	LL c=0, k=0;
	while(k<=odd){
		c+=comb(odd,k);
		k+=2;
	}
	ans=c*pow(2,N-odd);
	if(P) ans=pow(2,N)-ans;
	cout << ans << endl;

	return 0;
}
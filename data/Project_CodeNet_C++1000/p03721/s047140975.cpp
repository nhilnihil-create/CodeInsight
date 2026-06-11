#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define N 100100
lli n, k;

int main(void){
	cin >> n >> k;
	vector<lli> a(N);
	rep(i, n){
		lli ai, bi;
		cin >> ai >> bi;
		a[ai]+=bi;
	}
	lli s = 0;
	for(int i = 1; i <= N; i++){
		s+=a[i];
		if(s >= k){
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}

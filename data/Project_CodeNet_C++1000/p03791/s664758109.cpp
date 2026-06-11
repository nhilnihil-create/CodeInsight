#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int N = 2e5 + 5, MOD = 1e9 + 7;

int A[N];

int mult(int a, int b){
	ll ret = (a * 1LL * b) % MOD;
	return ret;
}

int main(){
	int n, cntr = 0, ans = 1;
	cin>>n;

	A[0] = -1;
	for(int i = 1; i <= n; i++)	cin>>A[i];

	for(int i = 1; i <= n; i++){
		A[i] = min(A[i - 1] + 2, A[i]);
		if(A[i] - A[i - 1] == 1){
			A[i]--;
			ans = mult(ans, cntr + 1);
		}
		else{
			cntr++;
		}
	}

	while(cntr){
		ans = mult(ans, cntr);
		cntr--;
	}

	cout<<ans<<endl;

	return 0;
}
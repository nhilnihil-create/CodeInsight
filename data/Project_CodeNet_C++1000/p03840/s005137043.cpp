#include <iostream>
using namespace std;
typedef long long ll;
ll A[7],B[7];

int main(){
	for(int i=0;i<7;i++){
		cin >> A[i];
		B[i] = A[i];
	}
	ll ans = 0,ans2 = 0;
	if(A[0]>=1 && A[3]>=1 && A[4]>=1){
		ans += 6;
		A[0]--;
		A[3]--;
		A[4]--;
		ans += A[1]*2;
		ans += (A[0]/2)*4;
		ans += (A[3]/2+A[4]/2)*4;
		A[0] -= A[0]/2;
		A[3] -= A[3]/2;
		A[4] -= A[4]/2;
	}
	ans2 += B[1]*2;
	ans2 += (B[0]/2)*4;
	ans2 += (B[3]/2+B[4]/2)*4;
	cout << max(ans,ans2)/2 << endl;
}


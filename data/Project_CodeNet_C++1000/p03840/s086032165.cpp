#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll A[7];
	for(int i=0; i<7; ++i) cin >> A[i];
	ll ans=A[1];
	if(A[0]<1 || A[3]<1 || A[4]<1){
	    cout << ans+(A[0]/2)*2+(A[3]/2)*2+(A[4]/2)*2 << endl;
	    return 0;
	}
	if(A[0]%2 + A[3]%2 + A[4]%2 >1){
	    ans += 3;
	    --A[0];
	    --A[3];
	    --A[4];
	}
	cout << ans+(A[0]/2)*2+(A[3]/2)*2+(A[4]/2)*2 << endl;
	return 0;
}


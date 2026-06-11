#include <bits/stdc++.h>

using namespace std;

int main() {
	long long I,O,T,J,L,S,Z; cin >> I >> O >> T >> J >> L >> S >> Z;
	long long ans=(I/2+J/2+L/2)*4;
	if(I&&J&&L) ans=max(ans,6+((I-1)/2+(J-1)/2+(L-1)/2)*4);
	ans+=O*2;
	cout << ans/2 << endl;
	
	return 0;
}

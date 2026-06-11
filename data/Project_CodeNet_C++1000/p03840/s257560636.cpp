#include <bits/stdc++.h>
using namespace std;

int main(){
	long long I,O,T,J,L,S,Z,ans=0;
	cin >> I >> O >> T >> J >> L >> S >> Z;
	ans=I/2*2+O+J/2*2+L/2*2;
	if(I%2+J%2+L%2==3)ans+=3;
	if(I%2+J%2+L%2==2 && I>0 && J>0 && L>0)ans+=1;
	cout << ans << endl;
	return 0;
}
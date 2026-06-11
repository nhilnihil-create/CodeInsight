#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli a, b, c;

int main(void){
	cin >> a >> b >> c;
	if(a %2 == 0 || b %2 == 0 || c%2 == 0) cout << 0 << endl;
	else{
		cout << min({a*b, b*c, c*a}) << endl;
	}
	return 0;
}

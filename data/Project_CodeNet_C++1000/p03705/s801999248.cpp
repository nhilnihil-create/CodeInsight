#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, a, b;

int main(void){
	cin >> n >> a >> b;
	if(a > b || (n == 1)&&(a != b)){
		cout << 0 << endl;
		return 0;
	}
	lli x = (n-1)*b+a;
	lli y = (n-1)*a+b;
	cout << x-y+1 << endl;
	return 0;
}

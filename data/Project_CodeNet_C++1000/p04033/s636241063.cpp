#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli a, b;

int main(void){
	cin >> a >> b;
	lli c;
	if(a == 0 || b == 0){
		cout << "Zero" << endl;
		return 0;
	}

	if(a < 0 && b < 0){
		c = b-a+1;
	}else if(a < 0 && b > 0){
		cout << "Zero" << endl;
		return 0;
	}else if(a > 0 && b > 0){
		c = 0;
	}
	if(c % 2 == 0) cout << "Positive" << endl;
	else cout << "Negative" << endl;
	return 0;
}

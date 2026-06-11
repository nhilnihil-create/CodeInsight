#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a, b, x, y;

int main() {
	cin>>a>>b;
	if(a <= 0 && b >= 0) {
		cout<<"Zero"<<endl;
		return 0;
	}
	if(0 <= a) {
		cout<<"Positive"<<endl;
		return 0;
	}
	if(a < 0 && b > 0) {
		cout<<(((-a)%2 == 1) ? "Negative":"Positive")<<endl;
		return 0;
	}
	cout<<(((b - a)%2 == 0) ? "Negative":"Positive")<<endl;
	return 0;
}
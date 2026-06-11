#include<bits/stdc++.h>

using namespace std;

long long n, a = 1, b = 1, x, y, t;

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x >> y;
		t = max((a+x-1)/x, (b+y-1)/y);
		a = t*x; b = t*y;
	}
	cout << a + b << endl;
}
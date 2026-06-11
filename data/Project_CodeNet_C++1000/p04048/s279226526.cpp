#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N, X, a, b, ans = 0;
	cin >> N >> X;
	a = X, b = N - X;
	if(a < b) swap(a, b);
	while(b){
		ans += (a/b) * b * 2;
		a %= b; swap(a, b);
	}
	cout << ans - a + N << endl;
	return 0;
}
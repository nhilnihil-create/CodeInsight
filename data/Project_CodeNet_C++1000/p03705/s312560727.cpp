#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	ll n, a, b; cin >> n >> a >> b;
	if(b < a)cout << 0;
	else if(n == 1 && b != a){
		cout << 0;
	}else if(n == 1 && b == a){
		cout << 1;
	}else{
		cout << (n - 2) * b - (n - 2) * a + 1;
	}
	
    return 0;
}

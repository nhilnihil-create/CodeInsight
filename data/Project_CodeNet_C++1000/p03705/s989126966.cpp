#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
	
	int n;
	long a, b;
	cin >> n >> a >> b;
	if(a > b) {
		cout << 0 << endl;
		return 0;
	}
	if(n == 1 && a < b){
		cout << 0 << endl;
		return 0;
	}
	cout << (n-1)*(b-a)+a-b+1 << endl;
	return 0;
}
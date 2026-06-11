#include<bits/stdc++.h>
using namespace std;

int main(){
	long long X, Y;
	cin >> X >> Y;
	if((X-Y) % 3 == 0){
		if(X == Y) cout << "Brown" << endl;
		else cout << "Alice" << endl;
	}else{
		if(abs(X-Y) == 1) cout << "Brown" << endl;
		else cout << "Alice" << endl;
	}
	return 0;
}
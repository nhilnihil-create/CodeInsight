#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	
	if(a+b == c || c+a == b || b+c == a){
		cout << "Yes";
		return 0;
	}
	
	cout << "No";
	return 0;
}

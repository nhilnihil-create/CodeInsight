#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	char op;
	cin >> a >> op >> b;
	int ans=0;
	if(op=='+') ans=a+b;
	if(op=='-') ans=a-b;
	cout << ans << endl;
}

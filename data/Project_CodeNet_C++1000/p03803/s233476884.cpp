#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if(a!=1 && b!=1){
		if(a>b) cout << "Alice" << endl;
		if(a==b) cout << "Draw" << endl;
		if(a<b) cout << "Bob" << endl;
	}
	if(a==1 && b!=1) cout << "Alice" << endl;
	if(a!=1 && b==1) cout << "Bob" << endl;
	if(a==1 && b==1) cout << "Draw" << endl;
}

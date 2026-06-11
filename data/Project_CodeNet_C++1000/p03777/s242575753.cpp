#include <bits/stdc++.h>
using namespace std;

int main(){
	char a, b;
	cin >> a >> b;
	bool judge;
	if(a=='H'){
		if(b=='H') judge=true;
		if(b=='D') judge=false;
	}
	if(a=='D'){
		if(b=='H') judge=false;
		if(b=='D') judge=true;
	}
	if(judge) cout << 'H' << endl;
	else cout << 'D' << endl;
}

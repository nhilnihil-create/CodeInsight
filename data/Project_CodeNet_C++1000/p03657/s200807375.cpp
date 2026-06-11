#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int wa=a+b;
	bool judge=false;
	if(a%3==0 || b%3==0 || wa%3==0) judge=true;
	if(judge) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}

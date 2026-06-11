#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, a, b;
	cin >> x >> a >> b;
	int saa = x-a;
	int sab = x-b;
	if(saa<0) saa=-saa;
	if(sab<0) sab=-sab;
	if(saa<=sab) cout << 'A' << endl;
	if(saa>sab) cout << 'B' << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, a, b;
	cin >> x >> a >> b;
	int sa=b-a;
	if(sa>x) cout << "dangerous" << endl;
	if(sa<=x && sa>0) cout << "safe" << endl;
	if(sa<=0) cout << "delicious" << endl;
}

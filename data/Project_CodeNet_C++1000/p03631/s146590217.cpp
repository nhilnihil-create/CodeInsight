#include <bits/stdc++.h>
using namespace std;

int main(){
	string n, sam;
	cin >> n;
	sam=n;
	reverse(sam.begin(), sam.end());
	if(n==sam) cout << "Yes" << endl;
	else cout << "No" << endl;
}

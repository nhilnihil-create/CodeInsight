#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> v(4);
	for (char c: s){
		if (c=='N') v[0]++;
		else if (c=='S') v[1]++;
		else if (c=='E') v[2]++;
		else if (c=='W') v[3]++;
	}
	if (!( (v[0] > 0) ^ (v[1] >0)) && !((v[2]>0) ^ (v[3]>0))) cout << "Yes";
	else cout << "No";
	
 }

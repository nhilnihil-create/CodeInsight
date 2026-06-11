#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	int n;
	n=str.size();
	for (int i=0; i<n; i+=2) cout << str.at(i);
	cout << endl;
}


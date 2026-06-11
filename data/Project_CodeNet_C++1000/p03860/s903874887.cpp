#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> s(3);
	for(int i=0; i<3; i++){
		cin >> s.at(i);
	}
	for(int i=0; i<3; i++){
		cout << s.at(i).at(0);
	}
	cout << endl;
}

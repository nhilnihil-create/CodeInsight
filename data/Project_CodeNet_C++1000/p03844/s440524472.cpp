#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	char ope;
	cin >> a >> ope >> b;
	if(ope == '+'){
		cout << stoi(a) + stoi(b) << endl;
	}else{
		cout << stoi(a) - stoi(b) << endl;
	}
}

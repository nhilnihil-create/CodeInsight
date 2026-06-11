#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	char ope;
	cin >> a >> ope >> b;
	cout << ((ope == '+') ? stoi(a) + stoi(b) : stoi(a) - stoi(b)) << endl;

}

#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int e = 0, w = 0, s = 0, n = 0;
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
		if (str[i] == 'S') s = 1;
		else if (str[i] == 'E') e = 1;
		else if (str[i] == 'W') w = 1;
		else n = 1;
	if ((s != n) || (e != w)) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}

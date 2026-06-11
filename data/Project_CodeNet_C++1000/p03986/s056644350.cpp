#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;

int main() {
	char str[250000];
	cin >> str;
	stack<char>q;
	q.push('1');
	char bt;
	int j = 0;
	while (str[j] != '\0') {
		//cout << 233 << endl;
		if (str[j] == 'S') q.push('S');
		if (str[j] == 'T') {
			bt = q.top();
			//cout << bt << endl;
			if ( bt=='T'|| bt=='1') q.push('T');
			else if (bt == 'S') {
				q.pop();
			}
		}
		j++;
	}
	cout << q.size()-1 << endl;
	return 0;
}
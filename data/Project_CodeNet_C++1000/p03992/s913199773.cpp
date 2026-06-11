#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	string s; cin >> s;
	for (int i = 0; i < 12; i++) {
		cout << s[i];
		if (i == 3) cout << " ";
	}
	cout << endl;
}
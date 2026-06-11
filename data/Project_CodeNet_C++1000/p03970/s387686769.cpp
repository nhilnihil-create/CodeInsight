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
	string S;
	string T = "CODEFESTIVAL2016";
	cin >> S;
	int count = 0;
	for (int i = 0; i < 16; i++) {
		if (S[i] != T[i]) {
			count++;
		}
	}
	cout << count << endl;
}
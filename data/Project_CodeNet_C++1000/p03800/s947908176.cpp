#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

bool test(string str,string res) {
	if (str[str.length() - 1] == 'o' && res[str.length() - 1] == 'S' && res[str.length() - 2] == res[0]) {
		
		return true;
	}
	else if (str[str.length() - 1] == 'o' && res[str.length() - 1] == 'W') {
		if (res[str.length() - 2] != res[0]) {
			return true;
		}
	}
	else if (str[str.length() - 1] == 'x' && res[str.length() - 1] == 'S') {
		if (res[str.length() - 2] != res[0]) {
			return true;
		}
	}
	else if (str[str.length() - 1] == 'x' && res[str.length() - 1] == 'W') {
		if (res[str.length() - 2] == res[0]) {
			return true;
		}
	}
	return false;
}
bool test2(string str, string res) {
	if (str[0] == 'o' && res[0] == 'S' && res[str.length() - 1] == res[1]) {

		return true;
	}
	else if (str[0] == 'o' && res[0] == 'W') {
		if (res[str.length() - 1] != res[1]) {
			return true;
		}
	}
	else if (str[0] == 'x' && res[0] == 'S') {
		if (res[str.length() - 1] != res[1]) {
			return true;
		}
	}
	else if (str[0] == 'x' && res[0] == 'W') {
		if (res[str.length() - 1] == res[1]) {
			return true;
		}
	}
	return false;
}

string solve(string str,string res) {
	for (int i = 2; i < str.length(); i++) {
		if (str[i - 1] == 'o' && res[i - 1] == 'S') {
			res.push_back(res[i - 2]);
		}
		else if (str[i - 1] == 'o' && res[i - 1] == 'W') {
			if (res[i - 2] == 'S') {
				res.push_back('W');
			}
			else {
				res.push_back('S');
			}
		}
		else if (str[i - 1] == 'x' && res[i - 1] == 'S') {
			if (res[i - 2] == 'S') {
				res.push_back('W');
			}
			else {
				res.push_back('S');
			}
		}
		else {
			res.push_back(res[i - 2]);
		}
	}
	return res;
}


int main() {
	complex<long double>cmpmp;
	const long long int mod = 1000000007;
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int n;
	string str,res,res2,res3,res4;
	cin >> n >> str;
	//ss
	res = "SS";
	res2 = "SW";
	res3 = "WS";
	res4 = "WW";
	res = solve(str, res);
	res2 = solve(str, res2);
	res3 = solve(str, res3);
	res4 = solve(str, res4);

	if (test(str, res)&& test2(str, res)) { cout << res << endl; return 0; }
	if (test(str, res2) && test2(str, res2)) { cout << res2 << endl; return 0; }
	if (test(str, res3) && test2(str, res3)) { cout << res3 << endl; return 0; }
	if (test(str, res4) && test2(str, res4)) { cout << res4 << endl; return 0; }
	
	cout << -1 << endl;
}

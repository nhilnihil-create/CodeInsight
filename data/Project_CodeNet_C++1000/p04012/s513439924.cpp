#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string w;
	cin >> w;

	vector<char> c{ 'a','b','c','d','e','f','g','h','i','j','k',
		'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	bool ans = true;

	for (char i : c) {
		int che = count(w.begin(), w.end(), i);
		if (che % 2 != 0) { 
			ans = false;
			break;
		}
	}

	if (ans) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

}
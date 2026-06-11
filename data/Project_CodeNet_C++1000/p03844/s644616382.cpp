#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;


int main() {
	int a, b;
	string s;
	cin >> a;
	cin >> s;
	cin >> b;
	if (s[0] == '+')cout << a+ b;
	if (s[0] == '-')cout << a - b;

}
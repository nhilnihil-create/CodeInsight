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
	
	string s[5];
	cin >> s[0] >> s[1] >> s[2];
	if (s[0].back() == s[1][0] && s[1].back() == s[2][0])cout << "YES";
	else cout << "NO";
}
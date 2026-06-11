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
	int a, b, c;
	cin >> a >> b >> c;
	multiset<int> ir;
	ir.insert(a);
	ir.insert(b);
	ir.insert(c);
	auto it = ir.begin();
	if (*it + *(++it) == *(++it))cout << "Yes";
	else cout << "No";
}
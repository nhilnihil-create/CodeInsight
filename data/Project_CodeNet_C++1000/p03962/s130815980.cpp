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
	set<int> ir;
	for (int i = 0; i < 3; i++) {
		int y;
		cin >> y;
		ir.insert(y);
	}
	cout << ir.size();
}
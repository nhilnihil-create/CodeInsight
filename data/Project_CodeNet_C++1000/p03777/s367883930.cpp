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
	
	string a, b;
	cin >> a >> b;
	if ((a[0] == 'D' && b[0] == 'H') || (a[0] == 'H' && b[0] == 'D')) {
		cout << 'D';
	}
	else cout << 'H';
}
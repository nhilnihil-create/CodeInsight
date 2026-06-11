#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <list>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	deque<int> a;
	int b;
	for (int i = 0 ; i < n ; i++) {
		cin >> b;
		if (i % 2) a.push_back(b);
		else a.push_front(b);
	}
	if (n % 2 == 0) reverse(a.begin(), a.end());
	for (int i = 0; i < n ; i++) cout << a[i] << ' ';
	/*
	vector<char> b;
	char a;
	for (int i = 0 ; i < n ; i++) {
		cin >> a;
		b.push_back(a);
		reverse(b.begin(), b.end());
		cout << b[i] << ' ';
	}
	*/
}
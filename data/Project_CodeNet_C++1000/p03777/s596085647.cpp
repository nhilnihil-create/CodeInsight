#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	char a, b;
	cin >> a >> b;
	
	if (a != 'H') {
		if (b == 'H') {
			b = 'D';
		} else {
			b = 'H';
		}
	}
	
	cout << b << endl;
  return 0;
}
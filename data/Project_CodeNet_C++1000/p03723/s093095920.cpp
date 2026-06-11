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
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a == b && b == c) {
		if (a % 2 == 0)
			cout << -1 << endl;
		else
			cout << 0 << endl;
	} else {
		int count = 0;
		while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
			int A = (b+c)/2;
			int B = (a+c)/2;
			int C = (a+b)/2;
			
			a = A;
			b = B;
			c = C;
			count++;
		}
		cout << count << endl;
	}
  return 0;
}
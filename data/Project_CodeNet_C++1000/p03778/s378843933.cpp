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
	int w;
	int a, b;
	cin >> w >> a >> b;
	
	int A = min(a, b);
	int B = max(a, b);
	
	cout << max(0, B-(A+w)) << endl;
  return 0;
}
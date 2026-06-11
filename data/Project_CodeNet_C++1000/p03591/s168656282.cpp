#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007
 

int main() {
	string s;
	cin >> s;
	if (s.length() < 4)print("No");
	else if (s[0] == 'Y'&&s[1] == 'A'&&s[2] == 'K'&&s[3] == 'I')print("Yes");
	else print("No");



	return 0;
}
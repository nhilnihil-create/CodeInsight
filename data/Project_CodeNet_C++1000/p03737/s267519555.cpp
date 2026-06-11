#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	transform(a.begin(), a.end(), a.begin(),::toupper);
	transform(b.begin(), b.end(), b.begin(), ::toupper);
	transform(c.begin(), c.end(), c.begin(), ::toupper);
	cout << a[0]<< b[0] << c[0] << endl;
}

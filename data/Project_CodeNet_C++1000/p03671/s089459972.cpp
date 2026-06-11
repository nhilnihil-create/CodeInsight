#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
	ll a, b, c; cin >> a >> b >> c;
	cout << min({ a + b,b + c,c + a }) << endl;
	return 0;
}
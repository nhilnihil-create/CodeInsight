#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include <assert.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include <iomanip>
#include<map>
#include <random>
#include<type_traits>
#include<stack>
#include <sstream> 
#include <limits>
#include <numeric>
#include<string.h>
#include<set>
#include <climits>
using namespace std;
typedef unsigned long long ull;
#define ll long long int
static const double PI = 3.141592653589793;
const ll INF = 100000000000000;
ll mod = 1000000007;
//typedef vector<int> V;
//typedef vector<V> VV;
//typedef vector<VV> VVV;

ll dp[3005][3005];



int main() {
	ll a, c, b, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	dp[0][0] = 1;
	for (int i = 0; i <= f; i++) {
		for (int j = 0; j + i <= f; j++) {
			if (dp[i][j] == 1) {
				if(i + 100 * a+j<=f)dp[i + 100 * a][j] = 1;
				if(i + 100 * b+j<=f)dp[i + 100 * b][j]=1;
				if(i+j+c<=f)dp[i][j + c] = 1;
				if(i+j+d<=f)dp[i][j + d] = 1;
			}
		}
	}
	ll aa=0, bb = 0;
	for (int i = 0; i <= f; i++) {
		for (int j = 0; j + i <= f; j++) {
			if (dp[i][j] == 1&&(i+j)!=0) {

				if ((i+j)*bb<=(aa+bb)*j&&100*j<=i*e) {
					aa = i;
					bb = j;
				}
			}
		}
	}
	cout << aa + bb << " " << bb << endl;

	return 0;
}
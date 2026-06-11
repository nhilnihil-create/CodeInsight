//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
//#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long long int ll;

//define
#define INF 1e9 
#define NUM 1000000007
#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int w, h;
	string s;
	cin >> w >> h;
	rep(i, w) {
		rep(j, h) {
			cin >> s;
			if (s == "snuke") {
				cout << (char)('A' + j) << i+1 << endl;
			}
		}
	}

	return 0;
	
}




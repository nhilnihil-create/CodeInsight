#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	string road;
	cin >> road;
	int no=0, so=0, we=0, ea=0;
	rep(i, road.size()) {
		switch (road.at(i))
		{
		case 'N' :
			no=1;
			break;
		case 'S':
			so=1;
			break;
		case 'W':
			we=1;
			break;
		case 'E':
			ea=1;
			break;
		default:
			break;
		}
	}
	if (no==so && we==ea)
	{
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
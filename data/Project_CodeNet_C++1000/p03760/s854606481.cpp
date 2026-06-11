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
	string O, E;
	cin >> O >> E;
	rep(i, O.size()) {
		if (O.size()==E.size())
		{
			cout << O.at(i) << E.at(i);
		}
		else {
			if (i==O.size()-1)
			{
				cout << O.at(i);
			}
			else {
				cout << O.at(i) << E.at(i);
			}
		}
		
	}
}
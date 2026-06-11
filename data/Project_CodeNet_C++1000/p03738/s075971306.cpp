#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	string A, B;
	cin >> A >> B;
	
	if (A.size()> B.size())
	{
		cout << "GREATER" << endl;
	}
	else if (A.size() < B.size()) {
		cout << "LESS" << endl;
	}
	else {
		rep(i, A.size()) {
			if (A.at(i) > B.at(i))
			{
				cout << "GREATER" << endl;
				return 0;
			}
			else if (A.at(i) < B.at(i)) {
				cout << "LESS" << endl;
				return 0;
			}
			else {
				continue;
			}
		}
		cout << "EQUAL" << endl;
	}
		return 0;
}
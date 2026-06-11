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
	string s;
	cin >> s;
	int A=0, Z=0;
	rep(i, s.size()) {
		if (s.at(i)=='A')
		{
			A = i;
			break;
		}
	}
	
	for (int i = A+1; i < s.size(); i++)
	{
		if (s.at(i)=='Z')
		{
			Z = i;
		}
	}
	cout << Z - A + 1 << endl;
}
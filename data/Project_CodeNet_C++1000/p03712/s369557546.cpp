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
	int H, W;
	cin >> H >> W;
	H += 2;
	W += 2;
	GraphC vec(H, vector<char>(W));
	for (int i = 1; i < H-1; i++)
	{
		for (int j = 1; j < W-1; j++)
		{
			cin >> vec.at(i).at(j);
		}
	}
	
	rep(i, H) {
		rep(j, W) {
			if (!(vec.at(i).at(j)>= 'a'&& vec.at(i).at(j)<='z' ))
			{
				vec.at(i).at(j) = '#';
			}
			cout << vec.at(i).at(j);
		}
		cout << endl;
	}
}
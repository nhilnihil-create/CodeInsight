#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<stack>
#include<map>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int INF = 1e10;
const int ZERO = 0;

typedef pair<int,int> P;

signed main() {
	int H,W,N;
	cin >> H >> W >> N;
	vector<pair<int,int>> vec(N);
	for(int i = 0;i < N;i++) {
		int A,B;
		cin >> A >> B;
		vec.at(i) = make_pair(A - 1,B - 1);
	}
	map<P,int> ma;
  	for(auto x:ma) {
      	x.second = 0;
    }
	for(int i = 0;i < N;i++) {
		for(int j = -1;j <= 1;j++) {
			for(int k = -1;k <= 1;k++) {
				if(vec[i].first + j >= 1 && vec[i].second + k >= 1 && vec[i].first + j < H - 1 && vec[i].second + k < W - 1) {
					ma[P(vec[i].first + j,vec[i].second + k)] += 1;
				}
			}
		}
	}
	vector<int> ret(10);
	for(int i = 0;i < 10;i++) {
		ret.at(i) = 0;
	}
	for(auto x:ma) {
		ret.at(x.second)++;
	}
	int cnt = 0;
	for(int i = 1;i < 10;i++) {
		cnt += ret.at(i);
	}
	ret.at(0) = (H - 2) * (W - 2) - cnt;
	for(int i = 0;i < 10;i++) {
		cout << ret.at(i) << endl;
	}
}
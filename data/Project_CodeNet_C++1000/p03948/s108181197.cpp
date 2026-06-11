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

signed main() {
	int N,T;
	cin >> N >> T;
	vector<int> vec(N);
	for(int i = 0;i < N;i++) {
		cin >> vec.at(i);
	}
	int minium = INF;
	int maxium = 0;
	for(int i = 1;i < N;i++) {
		minium = min(minium,vec.at(i - 1));
		maxium = max(maxium,vec.at(i) - minium);
	}
	minium = INF;
	int ret = 0;
	for(int i = 1;i < N;i++) {
		minium = min(minium,vec.at(i - 1));
		if(vec.at(i) - minium == maxium) {
			ret++;
		}
	}
	cout << ret << endl;
}
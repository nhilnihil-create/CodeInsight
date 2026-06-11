#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#define int long 
using namespace std;

signed main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	for(int i = 0;i < N;i++) {
		cin >> vec.at(i);
	}
	int A = 0;
	int B = 0;
	for(int i = 0;i < N;i++) {
		B += vec.at(i);
	}
	int count = 1e18;
	for(int i = 0;i < N - 1;i++) {
		A += vec.at(i);
		B -= vec.at(i);
		count = min(count,abs(A - B));
	}
	cout << count << endl;
}
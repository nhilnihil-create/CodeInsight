#include<iostream>
#include<cstdio>
#include<ios>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<list>
#include<utility>
#include<tuple>
#include<map>
#include<unordered_map>
#include<complex>
using namespace std;
typedef long long llong;
llong gcd(llong a, llong b) {
	if (a < b) std::swap(a, b);
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}
llong lcm(llong a, llong b) {
	llong g = gcd(a, b);
	return a * b / g;
}
//ここまで共通
int N;
vector<llong>A;
llong T;
llong ANS = 0;

int main() {
	cin >> N;
	cin >> T;
	for (int i = 0; i < N; i++) {
		llong a;
		cin >> a;
		A.push_back(a);
	}

	llong LowestPrice = 1000000007;
	llong HighestBenefit = 0;
	for (int i = 0; i < N; i++) {
		LowestPrice = min(LowestPrice, A[i]);
		HighestBenefit = max(HighestBenefit, A[i] - LowestPrice);
	}
	LowestPrice = 1000000007;
	for (int i = 0; i < N; i++) {
		LowestPrice = min(LowestPrice, A[i]);
		int Benefit = A[i] - LowestPrice;
		if (Benefit == HighestBenefit) {
			ANS++;
		}
	}
	cout << ANS << endl;
	return 0;
}
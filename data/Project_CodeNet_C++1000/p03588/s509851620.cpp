#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> P;
bool pairCompare(const P& firstElof, const P& secondElof)
{
    return firstElof.second > secondElof.second;
}
int main() {
	int N; cin >> N;
	vector<pair<long long, long long> >A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end(), pairCompare);
	cout << A[N - 1].first + A[N - 1].second << endl;
}
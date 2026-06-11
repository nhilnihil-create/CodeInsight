#include <iostream>
#include <map>
using namespace std;

int main() {
	string A;
	cin >> A;
	long long N = A.length();
	map<char, long long> Nums;
	for (char c : A) Nums[c]++;
	long long ans = N * (N - 1) / 2 + 1;
	for (auto& p : Nums) ans -= p.second * (p.second - 1) / 2;
	cout << ans << endl;
}
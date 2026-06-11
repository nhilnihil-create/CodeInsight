#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;


int main() {
	long long N,x;
	cin >> N >> x;
	vector<vector<long long>>cost(N,vector<long long>(N,mod*100000));
	for (size_t i = 0; i < N; i++)
	{
		cin >> cost.at(0).at(i);
	}
	for (size_t i = 0; i < N-1; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cost.at(i + 1).at((j + 1) % N) = min(cost.at(i).at(j), cost.at(i).at((j + 1) % N));
		}
	}
	//i周目の最小コスト：i周目までの最小値の和＋x*i
	vector<long long> scost(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			scost.at(i) += cost.at(i).at(j);
		}
		scost.at(i) += i * x;
	}
	sort(scost.begin(),scost.end());
	cout << scost.at(0) << endl;
}
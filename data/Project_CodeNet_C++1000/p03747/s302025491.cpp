#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
using ll = long long;
using namespace std;
using pii = pair<int, int>;
using pdi = pair<double, int>;

int N, L, T;
vector<int> X;
vector<int> W;

int main() {
	cin >> N >> L >> T;
	for (int i = 0; i < N; i++)
	{
		int tmpX;
		int tmpW;
		cin >> tmpX >> tmpW;
		X.push_back(tmpX);
		W.push_back(tmpW);
	}

	vector<int> Xd;
	for (int i = 1; i < N; i++)
	{
		if (W.at(i) != W.at(0)) {
			Xd.push_back(X.at(i) * 2);
		}
	}

	int cnt = 0;
	const int Ld = L * 2;
	const int Td = T * 2;
	const int X0d = X.at(0) * 2;
	for (int i = 0; i < Xd.size(); i++)
	{
		int td = 0;
		if (W.at(0) == 1) {
			td += (Xd.at(i) - X0d) / 2;
		}
		else {
			td += (Ld - Xd.at(i) + X0d) / 2;
		}
		if (td < Td) {
			cnt++;
		}
		else {
			continue;
		}
		cnt += ((Td - td - 1) / (Ld / 2)) % N;
		cnt %= N;
	}
	vector<int> Xfinal;
	int X0final;
	for (int i = 0; i < N; i++)
	{
		int tmpXfinal = X.at(i);
		if (W.at(i) == 1) {
			tmpXfinal += T;
		}
		else {
			tmpXfinal -= T;
		}
		tmpXfinal %= L;
		tmpXfinal += L;
		tmpXfinal %= L;
		Xfinal.push_back(tmpXfinal);
		if (i == 0) {
			X0final = tmpXfinal;
		}
	}
	sort(Xfinal.begin(), Xfinal.end());

	int did;
	if (W.at(0) == 1) {
		for (int i = 0; i < N; i++)
		{
			if (Xfinal.at(i) == X0final) {
				did = i - cnt;
				break;
			}
		}
	}
	else {
		for (int i = N - 1; i >= 0; i--)
		{
			if (Xfinal.at(i) == X0final) {
				did = i + cnt;
				break;
			}
		}
	}
	did += N;
	did %= N;

	for (int i = 0; i < N; i++)
	{
		cout << Xfinal.at((i + did) % N) << endl;
	}

	return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>

using namespace std;

namespace {

}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> stud;
	vector<pair<int, int>> check;

	for (int i = 0; i < N; ++i){
		int a, b;
		cin >> a >> b;
		stud.push_back(make_pair(a, b));
	}
	for (int i = 0; i < M; ++i){
		int c, d;
		cin >> c >> d;
		check.push_back(make_pair(c, d));
	}

	for (int i = 0; i < N; ++i){
		int curA = stud[i].first;
		int curB = stud[i].second;

		int minIndex = -1;
		int minDst = -1;
		for (int j = 0; j < M; ++j){
			int curD = abs(check[j].first - curA) + abs(check[j].second - curB);
			if (minDst == -1 || minDst > curD){
				minIndex = j;
				minDst = curD;
			}
		}

		cout << minIndex + 1<< endl;
	}

	return 0;
}
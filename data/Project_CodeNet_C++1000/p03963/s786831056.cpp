#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>
#include<queue>

using namespace std;


int main() {
	int N, K;
	cin >> N >> K;

	cout << int64_t( pow((K - 1), (N - 1)) * K) << endl;;
}
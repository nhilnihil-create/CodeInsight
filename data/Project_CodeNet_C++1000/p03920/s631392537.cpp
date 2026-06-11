#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	int N;
	cin >> N;
	int n = ceil((sqrt(1+8*N)-1)/2);
	while(N) {
		int k = min(n,N);
		cout << k << "\n";;
		N -= k;
		--n;
	}
	return 0;
}
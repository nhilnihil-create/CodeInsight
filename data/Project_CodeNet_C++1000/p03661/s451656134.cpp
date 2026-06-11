#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	long long int sum_a[200001] = {};
	for(int i = 0; i < n; i++){
		long long int a;
		cin >> a;
		if(i > 0) sum_a[i] = sum_a[i - 1];
		sum_a[i] += a;
	}
	long long int ans = (long long int)mod * 200001;
	for(int i = 0; i < n - 1; i++){
		ans = min(ans, abs(sum_a[i] - (sum_a[n - 1] - sum_a[i])));
	}
	cout << ans << endl;
}
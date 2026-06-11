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

using namespace std;

#define mod 1000000007

int main()
{
	long long int n, k;
	cin >> n >> k;
	long long int a[100001], b[100001];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	long long int maxketa = 30;
	while(k < (long long int)(1 << maxketa)){
		maxketa--;
	}
	long long int nownum = (long long int)(1 << (maxketa + 1)) - 1;
	long long int ans = 0;
	for(int i = 0; i < n; i++){
		if((k | a[i]) == k) ans += b[i];
	}
	for(int i = maxketa; i >= 0; i--){
		nownum -= (long long int)(1 << i);
		// cout << i << " " << nownum << endl;
		if((k & (long long int)(1 << i)) == 0 && i > 0) continue;
		long long int result = 0;
		for(int j = 0; j < n; j++){
			if((a[j] | nownum) == nownum) result += b[j];
		}
		// cout << result << endl;
		ans = max(ans, result);
		nownum += (long long int)(1 << i);
	}
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <cmath>

using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);++(i))

int n;

i64 a[100010];

int main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i];
	int result = 0;
	rep(i,1,n - 1)
		if(a[i] == i)
		{
			result++;
			swap(a[i],a[i + 1]);
		}
  if(a[n] == n) result++;
	cout << result << endl;
}


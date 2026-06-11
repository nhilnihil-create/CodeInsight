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
#define pi atan(1) * 4
int swapresult[100001][61];

int main()
{
	int n;
	cin >> n;
	int x[100001];
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	long long int m, k;
	cin >> m >> k;
	int a[100001];
	for(int i = 0; i < m; i++){
		cin >> a[i];
		a[i]--;
	}
	int dy[100001];
	for(int i = 0; i < n - 1; i++){
		dy[i] = x[i + 1] - x[i];
	}
	for(int i = 0; i < n; i++){
		swapresult[i][0] = i;
	}
	for(int i = 0; i < m; i++){
		swap(swapresult[a[i]][0], swapresult[a[i] - 1][0]);
	}
	for(int i = 0; i < 60; i++){
		for(int j = 0; j < n; j++){
			swapresult[j][i + 1] = swapresult[swapresult[j][i]][i];
		}
	}
	for(int i = 60; i >= 0; i--){
		long long int tmp = pow(2, i);
		if(k >= tmp){
			k -= tmp;
			int newdy[100001];
			for(int j = 0; j < n; j++){
				newdy[j] = dy[swapresult[j][i]];
			}
			for(int j = 0; j < n; j++){
				dy[j] = newdy[j];
			}
		}
	}
	printf("%.10f\n", x[0] + 0.0);
	double now = x[0] + 0.0;
	for(int i = 0; i < n - 1; i++){
		printf("%.10f\n", now + (double)dy[i]);
		now += (double)dy[i];
	}
	return 0;
}
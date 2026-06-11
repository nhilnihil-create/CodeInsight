#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;



int main(){
	int n,m;
	long long x[100000];
	long long y[100000];

	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%lld", &x[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%lld", &y[i]);
	}

	long long sumx = 0;
	long long sumy = 0;
	for(int i=0;i<n;i++){
		sumx += i*x[i] + (n-1-i)*(-x[i]);
	}
	sumx %= 1000000007;
	for(int i=0;i<m;i++){
		sumy += i*y[i] + (m-1-i)*(-y[i]);
	}
	sumy %= 1000000007;

	long long ans = (sumx * sumy)%1000000007;
	printf("%lld\n", ans);

	return 0;
}

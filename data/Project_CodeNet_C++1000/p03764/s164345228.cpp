#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ull)1e9+7)
#define MAX ((ull)1e9)

int main(){
	int n, m;
	cin >> n >> m;

	ll x[n];
	cin >> x[0];
	ll sx=x[0], dx=0;
	for(int i=1; i<n; i++){
		cin >> x[i];
		dx+=i*x[i]-sx;
		sx+=x[i];
		dx%=mod;
	}

	ll y[m];
	cin >> y[0];
	ll sy=y[0], dy=0;
	for(int i=1; i<m; i++){
		cin >> y[i];
		dy+=i*y[i]-sy;
		sy+=y[i];
		dy%=mod;
	}

	cout << dx*dy%mod << endl;
	return 0;
}
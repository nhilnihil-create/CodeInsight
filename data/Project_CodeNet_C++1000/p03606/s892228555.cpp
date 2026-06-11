#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	int n;
	cin>>n;
	ll ans = 0;
	for(int i = 0; i < n; i ++){
		int left,right;
		cin>>left>>right;
		ans += (right - left) + 1;
	}
	cout<<ans<<endl;
	return 0;
}


#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	int n,k;
	cin>>n>>k;
	ll ans = k;
	for(int i = 1; i < n; i++){
		ans = ans * (k-1);
	}
	cout<<ans<<endl;
	return 0;
}


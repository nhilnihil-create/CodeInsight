#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long int ll;


int main()
{
	ll n,m;
	cin>>n>>m;
	ll ans = 0;
	if( 2*n >= m){
		ans = m / 2;
	}else{
		ans = n;
		m = m - 2*n;
		ans += m / 4;
	}
	cout<<ans<<endl;
	return 0;
}


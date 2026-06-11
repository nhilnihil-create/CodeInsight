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
#include <climits>
#include <bitset>
#include <list>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	bool appear=false;
	for(int k=0; k<n; k++){
		if((n-1-k)*c-k*d<=b-a && b-a<=(n-1-k)*d-k*c) appear=true;
	}
	if(appear) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
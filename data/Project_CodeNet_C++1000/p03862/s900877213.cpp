#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main()
{
	int N,X;
	cin>>N>>X;
	vector<int> a(N,0);
	rep(i,N) cin>>a[i];
	vector<int> b(N-1,0);
	vector<int> c(N-1,0);
	vector<int> nextA(N,0);
	ll sumOfDelta = 0;
	
	if( a[0] > X){
		nextA[0] = X;
	}else{
		nextA[0] = a[0];
	}
	for(int i = 1; i < N; i++){
		if( nextA[i-1] + a[i] <= X){
			nextA[i] = a[i];
		}else{
			nextA[i] = a[i] - ((nextA[i-1] + a[i]) - X );
		}
	}
	ll ans = 0;
	for(int i = 0; i < N; i++){
		ans += a[i] - nextA[i];
	}
	cout<<ans<<endl;
	return 0;
}

#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef unsigned long long int ll;

int main()
{
	const ll MAX_N = 1000000000000000000;
	ll n;
	cin>>n;
	ll left,right;
	cin>>left>>right;
	for(int i = 1; i < n; i++){
		ll t,a;
		cin>>t>>a;
		ll j,leftJ,rightJ;
		if( left % t == 0){
			leftJ = left / t;
		}else{
			leftJ = (left / t) + 1;
		}
		if( right % a == 0){
			rightJ = right /a;
		}else{
			rightJ = (right / a) + 1;
		}
		j = max(leftJ,rightJ);
		for( ; j*max(a,t) <= MAX_N; j++){
			if( j*a >= right && j*t >= left){
				left = j*t;
				right = j*a;
				break;
			}
		}
	}
	cout<<left+right<<endl;
	return 0;
}

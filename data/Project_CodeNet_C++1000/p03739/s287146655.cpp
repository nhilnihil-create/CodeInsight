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
typedef long long int ll;

int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> cumSum(n);
	rep(i,n) cin>>a[i];
	cumSum[0] = a[0];
	for(int i = 1; i < n; i++){
		cumSum[i] = cumSum[i-1] + a[i];
	}
	ll evenAns = 0;
	ll oddAns = 0;
	ll offset = 0;
	ll ans = 0;
	// 0番目が正になる場合
	for(int i = 0; i < n; i++){
		if( i % 2 == 0 ){
			if( cumSum[i] + offset > 0){
				// do nothing
			}else if( cumSum[i] + offset <= 0){
				int x = 1 - offset - cumSum[i];
				evenAns += abs(x);
				offset = offset + x;
			}
		}else{
			if( cumSum[i] + offset < 0){
				// do nothing
			}else if( cumSum[i] + offset >= 0){
				int x = -1 - offset - cumSum[i];
				evenAns += abs(x);
				offset = offset + x;
			}
		}
		//cout<<cumSum[i] + offset<<" ";
	}
	//cout<<endl;

	// 0番目が負になる場合
	offset = 0;
	for(int i = 0; i < n; i++){
		//偶数番目が負
		if( i % 2 == 0 ){
			if( cumSum[i] + offset < 0){
				// do nothing
			}else if( cumSum[i] + offset >= 0){
				int x = -1 - offset - cumSum[i];
				oddAns += abs(x);
				offset = offset + x;
			}
		}else{
			if( cumSum[i] + offset > 0){
				// do nothing
			}else if( cumSum[i] + offset <= 0){
				int x = 1 - offset - cumSum[i];
				oddAns += abs(x);
				offset = offset + x;
			}
		}
	}
	cout<<min(evenAns,oddAns)<<endl;
	return 0;
}

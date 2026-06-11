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
typedef long long ll;

int countBit(int bit){
	if(bit == 0){
		return 0;
	}
	if( bit & (1<<0)){
		return 1 + countBit( (bit>>1));
	}else{
		return countBit( (bit>>1));
	}
}

int main()
{
	int N,K;
	cin>>N>>K;
	N--;
	K--;
	int leftEnd;
	cin>>leftEnd;
	int *a = new int[N];
	rep(i,N) cin>>a[i];
	ll ans = 1000000000000;
	for(int bit = 0; bit < (1<<N); bit++){
		int leftHeight = leftEnd;
		if( countBit(bit) == K){
			ll localCostSum = 0;
			for(int i = 0; i < N; i++){
				if( bit & (1<<i)){
					if( leftHeight >= a[i]){
						leftHeight += 1;
						localCostSum += (leftHeight - a[i]); 
					}else{
						leftHeight = a[i];
					}
				}else{
					leftHeight = max(leftHeight,a[i]);
				}
			}
			ans = min(ans,localCostSum);
		}
	}
	cout<<ans<<endl;
	return 0;
}


//agc008_b.cpp
//Sun Jul 28 21:54:45 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,k;
	cin >> n >> k;

	ll a[n];
	ll ruiseki[n+1];
	ll plusruiseki[n+1];
	ruiseki[0] = 0;
	plusruiseki[0] = 0;
	for (int i=0;i<n;i++){
		cin >> a[i];
		ruiseki[i+1] = ruiseki[i]+a[i];
		if (a[i]>0){
			plusruiseki[i+1] = plusruiseki[i]+a[i];
		}else {
			plusruiseki[i+1] = plusruiseki[i];
		}
	}

	ll ans = 0;
	for (int i=0;i<=n-k;i++){
		ll temp = 0;
		if (ruiseki[i+k]-ruiseki[i]>0){
			temp +=  ruiseki[i+k]- ruiseki[i];
		}
		temp += plusruiseki[i]-plusruiseki[0]+
				plusruiseki[n]-plusruiseki[i+k];
		if (ans<temp){
			ans = temp;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}
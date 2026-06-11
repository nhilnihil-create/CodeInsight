//agc004_b.cpp
//Sat Jul 27 19:05:51 2019

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
	ll n,x;
	cin >> n >> x;

	ll a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	ll ans = LLINF;
	ll b[n];
	fill(b,b+n,LLINF);
	for (int i=0;i<n;i++){
		ll temp = 0;
		for (int j=0;j<n;j++){
			int index;
			if (j-i>=0){
				index = j-i;
			}else{
				index = n-i+j;
			}
			b[j] = min(b[j],a[index]);
			temp += b[j];
		}
		ans = min(ans,temp+i*x);
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}
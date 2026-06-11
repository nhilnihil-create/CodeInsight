//arc075_d.cpp
//Tue Jul  9 21:52:46 2019

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
	ll n,a,b;
	cin >> n >> a >> b;

	ll h[n];
	for (int i=0;i<n;i++){
		cin >> h[i];
	}

	sort(h,h+n,greater<ll>());

	int start = 0;
	int end = h[0]/b+2;
	ll ans = LLINF;
	while (abs(start-end)>1){
		ll mid = (start+end)/2;
		ll temp = 0;
		for (int i=0;i<n;i++){
			if (h[i]>mid*b){
				ll x = (h[i]-mid*b)/(a-b);
				if ((h[i]-mid*b)%(a-b)!=0){
					x++;
				}
				temp = temp + x;
			}
		}
//		cout << start << " " << end << " " << temp << " " << mid << endl;
		if (temp<=mid){
			if (ans > mid){
				ans = mid;
			}
			end = mid;
		}else {
			start = mid;
		}
	}
	cout << ans << endl;
}
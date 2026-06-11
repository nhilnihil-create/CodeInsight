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
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	ll w;
	cin >> n >> w;
	vector<ll> v[4];
	ll w_;
	for(int i=0; i<n; i++){
		ll a, b;
		cin >> a >> b;
		if(i==0) w_=a;
		v[a-w_].push_back(b);
	}
	for(int i=0; i<4; i++) sort(v[i].begin(), v[i].end(), greater<ll>());

	ll ans=0, weight=0;
	for(int i=0; i<=v[0].size(); i++){
		for(int j=0; j<=v[1].size(); j++){
			for(int k=0; k<=v[2].size(); k++){
				for(int l=0; l<=v[3].size(); l++){
					if(i*w_+j*(w_+1)+k*(w_+2)+l*(w_+3)>w) continue;
					ll value=0;
					for(int m=0; m<i; m++) value+=v[0][m];
					for(int m=0; m<j; m++) value+=v[1][m];
					for(int m=0; m<k; m++) value+=v[2][m];
					for(int m=0; m<l; m++) value+=v[3][m];
					ans=max(ans, value);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
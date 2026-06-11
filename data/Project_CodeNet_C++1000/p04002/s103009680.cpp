//arc061_d.cpp
//Thu Jul  4 22:08:52 2019

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
	ll h,w,n;
	cin >> h >> w >> n;

	vector<P> pos;

	for (int i=0;i<n;i++){
		ll a,b;
		cin >> a >> b;
//		cout << a << " " << b << endl;
		for (int j=0;j<3;j++){
			for (int k=0;k<3;k++){
				if (a-j>0 && b-k>0 && a-j<=h-2 && b-k<=w-2){
					P temp = make_pair(a-j,b-k);
					pos.push_back(temp);
//					cout << " " << a-j << " " << b-k << endl;
				}
			}
		}
	}

	sort(pos.begin(),pos.end());

	ll ans[9];
	fill(ans,ans+9,0);
	ll prevfirst = -1;
	ll prevsecond = -1;
	ll plus = 0;
	int count = 0;
	for (int i=0;i<pos.size();i++){
//		cout << " " << pos[i].first << " " << pos[i].second << endl;
		if (pos[i].first == prevfirst &&
			pos[i].second == prevsecond){
			count++;
		}else {
			plus++;
			if (count > 0){
				ans[count-1]++;
			}
			count = 1;
		}
		prevfirst = pos[i].first;
		prevsecond = pos[i].second;
	}
	if (count>0){
		ans[count-1]++;
	}

	ll anszero = (h-2)*(w-2)-plus;
	cout << anszero << endl;

	for (int i=0;i<9;i++){
		cout << ans[i] << endl;
	}
}
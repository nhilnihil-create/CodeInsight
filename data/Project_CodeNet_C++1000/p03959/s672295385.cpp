//cod2016_qualC_c.cpp
//Sun Aug  4 17:23:50 2019

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
	int n;
	cin >> n;

	int t[n];
	int h[n];
	fill(h,h+n,0);
	int flag[n];
	fill(flag,flag+n,0); //1->fixed 2->upper limit selected.
	for (int i=0;i<n;i++){
		cin >> t[i];
		if (i==0 || t[i]!=t[i-1]){
			h[i] = t[i];
			flag[i] = 1;
		}else{
			h[i] = t[i];
			flag[i] = 2;
		}
	}

	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	for (int i=n-1;i>=0;i--){
		if (i==n-1 || a[i]!=a[i+1]){
			if (flag[i] == 1 && a[i]!=h[i]){
				cout << 0 << endl;
				return 0;
			}else if (flag[i] == 2 && a[i]>h[i]){
				cout << 0 << endl;
				return 0;
			}else {
				h[i] = a[i];
				flag[i] = 1;
			}
		}else {
			if (flag[i] == 1 && a[i]<h[i]){
				cout << 0 << endl;
				return 0;
			}else if (flag[i] == 2 && a[i]<h[i]){
				h[i] = a[i];
			}
		}
	}

	ll ans = 1;
	for (int i=0;i<n;i++){
		if (flag[i]==2){
			ans = ans * h[i] % 1000000007;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}
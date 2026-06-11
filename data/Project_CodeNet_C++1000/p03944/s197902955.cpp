#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int w,h,n;
	cin >> w >> h >> n;
	vector<int> a(n);
	vector<int> x(n);
	vector<int> y(n);
	rep(i,n) cin >> x[i] >> y[i] >> a[i];
	int xmin = 0;
	int ymin = 0;
	rep(i,n){
		if(a[i] == 1){
			xmin = max(xmin,x[i]);
		}
		else if(a[i] == 2){
			w = min(w,x[i]);
		}
		else if(a[i] == 3){
			ymin = max(ymin,y[i]);
		}
		else if(a[i] == 4){
			h = min(h,y[i]);
		}
	if((w-xmin)*(h-ymin) <= 0){
	 cout << 0 << endl;
	 return 0;
	}
	}
	cout << (w-xmin)*(h-ymin) << endl;
}
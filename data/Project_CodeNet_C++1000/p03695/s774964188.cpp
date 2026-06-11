#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int grey = 0;
	int cha = 0;
	int green = 0;
	int mizu = 0;
	int blue = 0;
	int ki = 0;
	int dai = 0;
	int red = 0;
	int any = 0;
	rep(i,n){
		if(a[i] < 400) grey = 1;
		else if(a[i] < 800) cha = 1;
		else if(a[i] < 1200) green = 1;
		else if(a[i] < 1600) mizu = 1;
		else if(a[i] < 2000) blue = 1;
		else if(a[i] < 2400) ki = 1;
		else if(a[i] < 2800) dai = 1;
		else if(a[i] < 3200) red = 1;
		else any++;
	}
	int type = grey + cha + green + mizu + blue + ki + dai + red;
	if(type == 0){
	cout << 1 << " " << type + any << endl;
	return 0;
	}
	cout << type << " " << type + any << endl;
}

// cout << fixed << setprecision(15) <<  << endl;
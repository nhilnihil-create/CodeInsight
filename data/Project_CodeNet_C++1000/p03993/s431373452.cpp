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
	int counts = 0;
	rep(i,n){
		if(a[a[i]-1] == i+1)counts++;
 	}
	cout << counts/2 << endl;
}

// cout << fixed << setprecision(15) <<  << endl;
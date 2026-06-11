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
	int counts = 1;
	bool up = false;
	bool down = false;
	for(int i = 1; i < n; i++){
		int dif = a[i] - a[i-1];
		if(dif > 0) up = true;
		if(dif < 0) down = true;
		if(up && down){
			counts++;
			up = down = false;
			continue;
		}
	}
	cout << counts << endl;
}
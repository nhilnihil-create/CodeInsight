#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int x, y;
	cin >> x >> y;
	vector<int> a(12);
	a.at(0) = 0;
	a.at(2) = 0;
	a.at(4) = 0;
	a.at(6) = 0;
	a.at(7) = 0;
	a.at(9) = 0;
	a.at(11) = 0;
	a.at(3) = 1;
	a.at(5) = 1;
	a.at(8) = 1;
	a.at(10) = 1;
	a.at(1) = 2;
	if(a.at(x-1) == a.at(y-1)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
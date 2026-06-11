#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	map<int,int> cnt;
	rep(i,n){
		int a;
		cin >> a;
		cnt[a]++;
	}
	int counts = 0;
	for(auto p : cnt){
		auto k = p.first;
		auto v = p.second;
		if(v%2 == 1) counts++;
	}
	cout << counts << endl;
}
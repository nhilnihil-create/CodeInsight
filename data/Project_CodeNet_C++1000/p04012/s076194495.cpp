#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string w;
	cin >> w;
	map<char,int> cnt;
	rep(i,w.size()){
		cnt[w[i]]++;
	}
	int counts = 0;
	for(auto x: cnt){
		auto k = x.first;
		auto v = x.second;
		if(v%2 == 0) counts++;
	}
	cout << (counts == cnt.size() ? "Yes" : "No") << endl;
}
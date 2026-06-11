#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for(int i=0; i<h; i++){
		cin >> a.at(i);
	}
	vector<string> ans(h+2);
	for(int i=0; i<w+2; i++){
		ans.at(0)+='#';
		ans.at(h+1)+='#';
	}
	for(int i=1; i<h+1; i++){
		ans.at(i)+='#';
		ans.at(i)+=a.at(i-1);
		ans.at(i)+='#';
	}
	for(int i=0; i<h+2; i++){
		cout << ans.at(i) << endl;
	}
}

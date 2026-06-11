#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<char>> c(h, vector<char>(w));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> c.at(i).at(j);
		}
	}
	vector<vector<char>> ans(2*h, vector<char>(w));
	for(int i=0; i<2*h; i++){
		for(int j=0; j<w; j++){
			ans.at(i).at(j)=c.at(i/2).at(j);
		}
	}
	for(int i=0; i<2*h; i++){
		for(int j=0; j<w; j++){
			cout << ans.at(i).at(j);
		}
		cout << endl;
	}
}

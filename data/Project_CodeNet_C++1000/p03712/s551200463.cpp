#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int h, w;
	cin >> h >> w;
	vector<string> vec(h);
	for(int i = 0; i<h; i++){
		cin >> vec[i];
	}
	for(int j=0; j < w+2; j++){
		cout << '#';
	}
	cout << endl;
	for(int i=0; i<h; i++){
		cout << '#' << vec[i] << '#' << endl;
	}
	for(int j=0; j<w+2; j++){
		cout << '#';
	}
}
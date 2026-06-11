#include <bits/stdc++.h>

using namespace std;

int main(){
	int height, width;
	cin >> height >> width;
	vector<string> pixcel(height);
	for(int i = 0; i < height; i++){
		cin >> pixcel[i];
	}

	for(int j = 0; j < width + 2; j ++){
		cout << '#';
	}
	cout << endl;

	for(int i = 0; i < height; i++){
		cout << '#' << pixcel[i] << '#' << endl;
	}

	for(int j = 0; j < width + 2; j ++){
		cout << '#';
	}
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;


int main() {
	int H, W;
	cin >> H >> W;
	int oneWord = 0;
	int twoWord = 0;
	int fourWord = 0;
	if (H % 2 == 1 && W % 2 == 1) {
		oneWord = 1;
		twoWord = H + W - 2;
		fourWord = H * W - oneWord - twoWord;
	}
	else if (H % 2 == 1) {
		twoWord = W;
		fourWord = H * W - twoWord;
	}
	else if (W % 2 == 1) {
		twoWord = H;
		fourWord = H * W - twoWord;
	}
	else {
		fourWord = H * W;
	}


	map<char, int> mp;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			char a = 0; 
			cin >> a;
			++mp[a];
		}
	}

	bool check = true;
	do {
		check = true;
		for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
			if (itr->second == 1) {
				--oneWord;
				--itr->second;
				check = false;
			}
			else if (itr->second >= 4 && fourWord != 0) {
				fourWord -= 4;
				itr->second -= 4;
				check = false;
			}
			else if (itr->second >= 2 && twoWord != 0) {
				twoWord -= 2;
				itr->second -= 2;
				check = false;
			}
		}
	} while (!check);

	if (oneWord == 0 && twoWord == 0 && fourWord == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
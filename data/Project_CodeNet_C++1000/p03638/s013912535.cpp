#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int H = 0, W = 0;
	int N = 0;

	cin >> H >> W;
	cin >> N;

	vector<int> vctNum(N);
	for (auto& elem : vctNum) {
		cin >> elem;
	}

	//vector<stringstream> str(H);
	vector<vector<int>> table(H, vector<int>(W, 0));
	vector<bool> dirPosi(N, true);
	int numRoomInLine = W;
	int count = 0;
	int lineIndex = 0;
	bool dirPosiFlg = true;
	for (int k = 0; k < N; ++k) { // color のループ
		int curNum = vctNum[k];

		if (numRoomInLine >= curNum) {
			// 最初の行内に収まる。
			for (int i = 0; i < curNum; ++i) {
				table[lineIndex][W - numRoomInLine + i]  = k + 1;
			}
			count += curNum;
			numRoomInLine -= curNum;
			if ((count % W) == 0) {
				dirPosi[lineIndex] = dirPosiFlg;
				++lineIndex;
				dirPosiFlg = !dirPosiFlg;
			}
		}
		else {
			// 最初の行に収まらない。

			for (int i = 0; i < numRoomInLine; ++i) {
				table[lineIndex][W - numRoomInLine + i] = k + 1;
				//cout << k + 1;
			}
			if (numRoomInLine != 0) {
				dirPosi[lineIndex] = dirPosiFlg;
				++lineIndex;
				dirPosiFlg = !dirPosiFlg;
			}
			count += numRoomInLine;
			curNum -= numRoomInLine;
			numRoomInLine = W;
			int numLines = curNum / W;
			int numRestCol2 = curNum % W;

			for (int j = 0; j < numLines; ++j) {
				for (int i = 0; i < W; ++i) {
					table[lineIndex][i] = k + 1;
					//cout << k + 1;
				}
				dirPosi[lineIndex] = dirPosiFlg;
				++lineIndex;
				// dirPosiFlg = !dirPosiFlg;
			}

			for (int i = 0; i < numRestCol2; ++i) {
				table[lineIndex][W - numRoomInLine + i] = k + 1;
				// cout << k + 1;
			}
			numRoomInLine = W - numRestCol2;
			count += curNum;
		}
	}
	
	for (int i = 0; i < H; ++i) {
		if (dirPosi[i] ) {
			for (const auto& elem : table[i]) {
				cout << " " << elem;
			}
			cout << endl;
		}
		else {
			for (auto elem = table[i].rbegin(); elem != table[i].rend(); ++elem) {
				cout << " " << *elem;
			}
			cout << endl;
		}
	}

	return 0;
}
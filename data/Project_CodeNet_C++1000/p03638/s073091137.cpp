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

	// 1本のvectorにしてから、後で行で切る。

	vector<int> lineTable(H * W, 0);

	int index = 0;
	for (int i = 0; i < N; ++i) {
		int curNum = vctNum[i];
		for (int j = 0; j < curNum; ++j) {
			lineTable[index + j] = i + 1;
		}
		index += curNum;
	}

	// ぶつ切りにする。
	bool dirPosi = true;
	int lastColor = 0;
	for (int j = 0; j < H; ++j) {
		// int index = j * W;
		for (int i = 0; i < W; ++i) {
			if (dirPosi) {
				cout << lineTable[j * W + i] << " ";
			}
			else {
				cout << lineTable[(j + 1) * W - i -1] << " ";
			}
		}
		cout << endl;
		dirPosi = !dirPosi;
	}

	return 0;
}
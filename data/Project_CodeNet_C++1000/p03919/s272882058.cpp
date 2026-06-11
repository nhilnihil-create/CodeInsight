#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> S(H * W);
	for (int i = 0; i < H * W; i++) {
		cin >> S[i];
		if (S[i] == "snuke") {
			cout << (char)(65 + i % W);
			cout << (i / W) + 1 << endl;
		}
	}
}
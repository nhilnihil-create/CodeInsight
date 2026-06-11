#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W; 
	vector<string>S(H);	
	for (int i = 0;i<H;++i) {
		cin >> S[i];
	}
	vector<string>ansS(H + 2);	
	for (int i = 0;i<W+2; ++i) {
		ansS[0] += "#";
		ansS[H + 1] += "#";
	}
	for (int i = 0;i<H;++i) {
		ansS[i + 1] += "#";
		ansS[i + 1] += S[i];
		ansS[i + 1] += "#";
	}
	for (int i = 0;i<H+2;++i) {
		cout << ansS[i] << endl;
	}
}
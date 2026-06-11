#include<iostream>
#include<string>
using namespace std;

const int MAX = 26;
int H, W;
string A[MAX][MAX];

void input()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}
}

void solve()
{
	int ans_i, ans_j;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] == "snuke") {
				ans_i = i + 1;
				ans_j = j + 65; //大文字に変換
			}
		}
	}
	printf("%c%d\n", (char)ans_j,ans_i);

}

int main()
{
	input();
	solve();
	return 0;
}
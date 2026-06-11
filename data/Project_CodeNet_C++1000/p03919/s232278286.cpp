#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string S[30][30];

int main() {

	int i, j;

	int H, W;

	int ans[2];

	scanf("%d %d", &H, &W);

	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> S[i][j];
			if (S[i][j] == "snuke") { 
				ans[0] = i;
				ans[1] = j; 
			}
		}
	}
	printf("%c%d\n",ans[1]+'A',ans[0]+1);

	return 0;
}
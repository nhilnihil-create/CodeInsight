#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
	string col = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int H, W;
	cin >> H >> W;
	string S;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> S;
			if (S == "snuke")
			{
				cout << col[j] << i + 1 << endl;
				return;
			}
		}
	}
}

int main()
{
	solve();
	return(0);
}
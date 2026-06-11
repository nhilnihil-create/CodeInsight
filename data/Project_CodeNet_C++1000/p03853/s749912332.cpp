#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> S( H );
	for( int i = 0; i < H; i++ )  {
		cin >> S[i];
	}

	for( int i = 1; i <= H * 2; i++ )  {
		int ii = (i + 1) / 2 - 1;
		cout << S[ii] << endl;
	}
}

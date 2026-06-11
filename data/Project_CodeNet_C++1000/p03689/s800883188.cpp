#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
 
const int maxn = 1e5 + 20, inf = 1e9+1;

int H, W, h, w;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> H >> W >> h >> w;
	if (H % h == 0 && W % w == 0)
		return cout << "No" << endl, 0;
	if (H % h)
	{
		cout << "Yes" << endl;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
				if (i % h == 0)
					cout << 1000*(h-1)-1 << ' ';
				else
					cout << -1000 << ' ' ;
			cout << endl;
		}
	}
	else
	{
		cout << "Yes" << endl;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
				if (j % w == 0)
					cout << 1000*(w-1)-1 << ' ';
				else
					cout << -1000 << ' ' ;
			cout << endl;
		}
	}

	return 0;
}
#include <bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	LL l, r, mid, no, wei; 
	string res;
	for(no = 0, wei = 100000000000000000LL; ; wei /= 10)
	{
		l = (no ? 0 : 1), r = 9;
		while(l < r)
		{
			mid = (l + r) >> 1;
			cout << "? " << (no * 10 + mid + 1) * wei - 1 << endl << flush;
			cin >> res;
			if(res[0] == 'Y') r = mid;
			else l = mid + 1;
		} 
		no = no * 10 + r;
		cout << "? " << no * wei << endl << flush;
		cin >> res;
		if(res[0] == 'Y')
		{
			if(no == 1)
				for(wei = 1;; wei *= 10)
				{
					cout << "? " << wei + 1 << endl << flush;
					cin >> res;
					if(res[0] == 'Y')
					{
						cout << "! " << wei << endl << flush;
						return 0;
					}
				}
			
			for(wei = 1;; wei *= 10)
			{
				cout << "? " << (no - 1) * wei << endl << flush;
				cin >> res;
				if(res[0] == 'N') break;
			} 
			cout << "! " << no * wei / 10 << endl << flush;
			return 0;
		}
	}
	return 0;
}
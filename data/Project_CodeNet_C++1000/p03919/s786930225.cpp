#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

string S[30][30];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H, W; cin >> H >> W;
	rep (i, H) rep (j, W) cin >> S[i][j];

	int res = -1;
	rep (i, H){
		rep (j, W){
			if (S[i][j] == "snuke"){
				res = W*i + j;
				break;
			} // end if
		} // end rep
		if (res != -1) break;
	} // end rep
	
	char col = (char)((res % W) + 'A');
	int  row = (res / W) + 1;	
	cout << col << row << endl;

	return 0;
}
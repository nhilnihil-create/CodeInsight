#include<bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; 
typedef pair<int, int> pii; 
typedef vector<pair<int, int> > vpii; 
typedef long long ll;
template<typename T, typename U> static void amin(T &x, U &y) {if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U &y) {if (y > x) x = y; }
#define rep(i, n) for (int (i)=0; (i)<(n); (i)++)
#define rer(i, l, u) for (int (i)=(int)(l); (i)<=(int)(u); (i)++)
#define reu(i, l, u) for (int (i)=(int)(l); (i)<(int)(u); (i)++)
int main () {
	int sx, sy, tx, ty;
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	int x = tx-sx, y = ty-sy;
	rep(i, y) cout << "U";
	rep(i, x) cout << "R";
	rep(i, y) cout << "D";
	rep(i, x) cout << "L";
	cout << "L";
	rer(i, 0, y) cout << "U";
	rer(i, 0, x) cout << "R";
	cout << "D";
	cout << "R";
	rer(i, 0, y) cout << "D";
	rer(i, 0, x) cout << "L";
	cout << "U";
	return 0;
}
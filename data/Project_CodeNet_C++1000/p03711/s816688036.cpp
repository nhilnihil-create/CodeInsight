#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	bool yes = false;
	if(x == 2 && y == 2) yes = true;
	if((x==4||x==6||x==9||x==11)&&(y==4||y==6||y==9||y==11)) yes = true;
	if((x==1||x==3||x==5||x==7||x==8||x==10||x==12)&&(y==1||y==3||y==5||y==7||y==8||y==10||y==12)) yes = true;
	if(yes) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
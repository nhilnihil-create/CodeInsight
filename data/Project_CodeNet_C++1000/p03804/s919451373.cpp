#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

char a[55][55];
char b[55][55];

int main(){
	int n,m;
	cin >> n >> m;
	rep(i,n)rep(j,n) cin >> a[i][j];
	rep(i,m)rep(j,m) cin >> b[i][j];
	bool ok = false;
	rep(i,n-m+1){
		rep(j,n-m+1) {
			bool flag = true;
			rep(k, m) {
				rep(l, m) {
					if(a[i+k][j+l] != b[k][l]) flag = false;
				}
			}
			if (flag) ok = true;
		}
	}
	if(ok){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}


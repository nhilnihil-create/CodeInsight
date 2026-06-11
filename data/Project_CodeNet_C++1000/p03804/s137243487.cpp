#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	rep(i, n) cin >> a.at(i);
	rep(i, m) cin >> b.at(i);
	int d = n - m + 1;
	int ans = 0;
	rep(i, d){
		rep(j, d){
			int f = 0;
			for(int ii=0; ii<m; ii++){
				for(int jj=0; jj<m; jj++){
					if(a.at(i+ii).at(j+jj) != b.at(ii).at(jj)) f = 1;
				}
			}
			if(f == 0){ ans = 1; break; }
		}
	}
	if(ans == 1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
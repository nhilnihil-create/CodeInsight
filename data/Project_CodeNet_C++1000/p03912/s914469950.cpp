#include"bits/stdc++.h"
using namespace std;

//define
#define ALL(a) a.begin(),a.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define debug(x) if(1)cout<<#x<<":"<<x<<endl;
#define DEBUG(x) if(1)cout<<#x<<":"<<x<<endl;
#define ll long long

//typedef
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(){
	int n;
	int m;
	cin >> n >> m;
	vector<int> x(n);
	int res = 0;
	vector<int> moded(m,0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		moded[x[i] % m]++;
	}

	sort(ALL(x));
	for (int i = 0; i < m; i++) {
		if (i != (m - i) % m) {
			int sa = min(moded[(m - i) % m], moded[i]);
			res += sa;
			moded[i] -= sa;
			moded[(m - i) % m] -= sa;
		}
		else {

			int sa = moded[i] / 2;
			res += sa;
			moded[i] -= sa * 2;
		}

	}
	for (int i = 1; i < n; i++) {
		if (x[i] == x[i - 1]&& moded[x[i]%m]>=2) {
			res++;
			moded[x[i] % m] -= 2;
			i++;
		}
	}

	cout << res << endl;
	return 0;



}


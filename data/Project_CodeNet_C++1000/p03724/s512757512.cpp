#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		a--,b--;
		v[a]++;
		v[b]++;
	}
	bool ok = true;
	rep(i,n){
		if(v[i] % 2 == 1) ok = false;
	}
	if(ok){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
    return 0;
}


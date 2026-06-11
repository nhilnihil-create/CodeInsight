#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	rep(i,m) cin >> a[i] >> b[i];
	map<int,int> cnt;
	rep(i,m){
		cnt[a[i]]++;
	}		
	rep(i,m){
		cnt[b[i]]++;
	}	
	for(int i = 1; i <= n; i++){
		cout << cnt[i] << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, h, w;
	cin>>h>>w>>n;
	vector<int> a(n);
	for(auto &x : a){
		cin>>x;
	}
	vector<vector<int> > ans(h, vector<int>(w));
	int ind = 0;
	for(int i = 0; i < h; i++){
		int st, en, di;
		if(i&1){
			st = w - 1; en = -1; di = -1;
		}else{
			st = 0; en = w; di = 1;
		}
		for(int j = st; j != en; j += di){
			ans[i][j] = ind + 1; a[ind]--;
			if(!a[ind])ind++;
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<'\n';
	}


	return 0;
}
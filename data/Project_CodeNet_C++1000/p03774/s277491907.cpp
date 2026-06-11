#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<long> a(n), b(n), c(m), d(m);
	for(int i=0; i<n; i++){
		cin >> a.at(i) >> b.at(i);
	}
	for(int i=0; i<m; i++){
		cin >> c.at(i) >> d.at(i);
	}
	vector<vector<long>> ans(n, vector<long>(m));
	vector<int> res(n);
	for(int i=0; i<n; i++){
		vector<long> sam(m);
		for(int j=0; j<m; j++){
			long x, y;
			x=a.at(i)-c.at(j);
			y=b.at(i)-d.at(j);
			if(x<0) x=-x;
			if(y<0) y=-y;
			ans.at(i).at(j)=x+y;
			sam.at(j)=ans.at(i).at(j);
		}
		sort(sam.begin(), sam.end());
		long min=sam.at(0);
		for(int j=0; j<m; j++){
			if(min==ans.at(i).at(j)){
				res.at(i)=j+1;
				break;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout << res.at(i) << endl;
	}
}

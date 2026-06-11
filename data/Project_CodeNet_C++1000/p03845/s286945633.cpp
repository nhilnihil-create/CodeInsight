#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n;
	vector<int> t(n);
	for(int i=0; i<n; i++){
		cin >> t.at(i);
	}
	cin >> m;
	vector<int> p(m), x(m);
	for(int i=0; i<m; i++){
		cin >> p.at(i) >> x.at(i);
	}
	int total=0;
	for(int i=0; i<n; i++) total+=t.at(i);
	vector<int> ans(m);
	for(int i=0; i<m; i++){
		int sa=x.at(i)-t.at(p.at(i)-1);
		ans.at(i)=total+sa;
	}
	for(int i=0; i<m; i++){
		cout << ans.at(i) << endl;
	}
}

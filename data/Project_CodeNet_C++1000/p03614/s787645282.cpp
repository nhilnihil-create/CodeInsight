#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> p, v;
template <class T>
void readVector(int n, vector<T> &v){
	for(int i=0; i<n; ++i){
		T t;
		cin >> t;
		v.push_back(t);
	}
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	readVector(n, p);
	for(int i=0; i<n; ++i)
		p[i] = i+1==p[i]?1:0;
//	for(int i=0; i<n; ++i)
//		cout << p[i] << (i==n-1?"\n":" ");
	for(int i=1; i<n; ++i)
		if(p[i] > 0)
			p[i] += p[i-1];
	for(int i=0; i<n-1; ++i)
		if(p[i] > 0 && p[i+1] == 0) v.push_back(p[i]);
	if(p[n-1] > 0) v.push_back(p[n-1]);
//	for(int i=0; i<(int)v.size(); ++i)
//		cout << v[i] << "\n";
	for(int i=0; i<(int)v.size(); ++i)
		ans += v[i]/2 + (v[i]%2);
	cout << ans << "\n";
}
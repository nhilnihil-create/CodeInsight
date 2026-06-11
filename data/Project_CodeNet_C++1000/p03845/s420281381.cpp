#include <bits/stdc++.h>
using namespace std;
int main (){
	int n, t, m, p, x;
	vector <int> tiempo;
	vector <int> r;
	vector <pair<int, int> > bebidas;
	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> t;
		tiempo.push_back(t);
	}
	int sum;
	cin >> m;
	for (int i=0;i<m;i++){
		cin >> p>>x;
		sum =0;
		for (int j=0;j<n;j++){
			if (j+1 != p) sum += tiempo[j];
			else sum += x;
		}
		r.push_back(sum);
		
	}
	
	for (int i=0;i<m; i++){
		cout << r[i]<<endl;
	}
	
	return 0;
}
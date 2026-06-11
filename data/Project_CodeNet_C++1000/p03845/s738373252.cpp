#include <bits/stdc++.h>
using namespace std;
int main (){
	vector <int> tiempos;
	vector <pair <int, int> > bebidas;
	pair <int, int> pares;
	vector <long long> r;
	int n, t, m, p ,x; long long suma;
	cin >>n;
	for (int i=0;i<n;i++){
		cin >> t;
		tiempos.push_back(t);
	}
	cin >> m;
	for (int i=1; i<=m;i++){
		cin >>p >>x;
		suma =0;
		
		for (int i=0; i<n; i++){
			if (i+1 != p) {
				suma += tiempos[i];
			}
			else {
				suma += x;
			}
		}
		r.push_back(suma);
	}
	
	for (int i=0;i<m;i++){
		cout << r[i] <<endl;
	}
	
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	// numero de problemas
	int N; cin >> N;
	//Tiempo(i)
	int suma_tiempos = 0;
	int t[105];
	
	for (int i = 1; i <= N; i++) {
		cin >> t[i];
		suma_tiempos += t[i];
	}
	
	vector<int> sumas;
	// numero de tipos de bebida
	int M; cin >> M;
	for (int i = 1; i <= M; i++) {
		int pi, xi;
		cin >> pi >> xi;
		
		int suma_nueva = suma_tiempos;
		
		suma_nueva -= t[pi];
		suma_nueva += xi;
		
		sumas.push_back(suma_nueva);
	}
	
	for (int i = 0; i < sumas.size(); i++) {
		cout << sumas[i] << endl;
	}
	
	
	/*
	vector<int> suma;
	vector<int> aux;
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++) {
			aux.push_back(T[j]);
		}
		
		if (pi[i] == i)
		aux[pi[i]] = xi[i];
		
	for (int k = 0; k < N; k++) {
		cout << aux[i] << " ";	
		}
	}
		//imprimir
	for (int i = 0; i < N; i++) {
		cout << aux[i] << " ";	
	}
	cout << endl;
	for (int i = 0; i < M; i++) {
		cout << pi[i] << " " << xi[i] << endl;	
	}
	*/
}
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, M, p, x;
	int aux1, aux2, aux3;
	cin >> N;
	int T[100000];
	int suma[1001];
	int tiaux[100000];
		for (int i = 0; i < N;i++) {
			cin >> aux1;
			T[i] = aux1;
			tiaux[i] = aux1;
			suma[i] = 0;
		}
		cin >> M;
		for (int j= 0; j < M; j++) {
			cin >> aux2;
			cin >> aux3;
			tiaux[(aux2)-1] = aux3;
			for (int x = 0; x < N; x++) {
				suma[j] += tiaux[x];
			}
			for (int o = 0; o < N; o++)
				tiaux[o] = T[o];
		}
		for (int e = 0; e < M; e++)
			cout << suma[e] << endl;
	return(0);
}
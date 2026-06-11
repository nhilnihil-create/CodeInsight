#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int N, L, T; 
	cin >> N >> L >> T; 
	int X[100010] = {}; 
	int W[100010] = {}; 
	int Aft[100010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> X[i] >> W[i]; 
		if(W[i] == 1){Aft[i] = (X[i] + T) % L;}
		else if(W[i] == 2){Aft[i] = (L + X[i] - (T % L)) % L;}
	}
	sort(Aft, Aft + N); 
	int F = 0; // 非負の座標にいる蟻の番号の最小値
	for(int i = 0; i < N; i++){
		int A = 0; 
		if(W[i] == 1){A = max(T + X[i], 0) / L ;
			F = (N + F - (A % N)) % N;}
		else if(W[i] == 2){A = max(T + L - X[i] - 1, 0) / L;
			F = (F + (A % N)) % N;}
	}
	for(int i = 0; i < F; i++){
		cout << Aft[N + i - F] << endl; 
	}
	for(int i = F; i < N; i++){
		cout << Aft[i - F] << endl; 
	}
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;

int main(){
	int N; cin >> N;
	int a[N+1], b[N+1];
	for(int i=1; i<=N; i++){ a[i] = 20000*i; b[i] = 20000*(N-i+1); }
	for(int i=0; i<N; i++){
		int p; cin >> p;
		a[p] += i; b[p] += i;
	}
	for(int i=1; i<=N; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
	for(int i=1; i<=N; i++){
		cout << b[i] << " ";
	}
	cout << "\n";
	return 0;
}

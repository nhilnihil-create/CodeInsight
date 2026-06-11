#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> p(N);
	for (int i = 0; i < N; i++){
		cin >> p[i];
		p[i]--;
	}
	vector<int> a(N, 0);
	for (int i = 0; i < N; i++){
		a[i] += N * i;
	}
	for (int i = 0; i < N; i++){
		a[p[i]] += i;
	}
	vector<int> b(N, 0);
	for (int i = 0; i < N; i++){
		b[i] += N * (N - 1 - i);
	}
	for (int i = 0; i < N; i++){
		b[p[i]] += i;
	}
	for (int i = 0; i < N; i++){
		cout << a[i] + 1;
		if (i < N - 1){
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++){
		cout << b[i] + 1;
		if (i < N - 1){
			cout << ' ';
		}
	}
	cout << endl;
}
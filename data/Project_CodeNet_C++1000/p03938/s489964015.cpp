#include<iostream>

using namespace std;

int p[20000];
int ar[20000];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		ar[p[i] - 1] = i;
	}
	int a[20000], b[20000];
	for (int i = 1; i <= N; i++) {
		a[i - 1] = 25000 * i;
		b[i - 1] = 25000 * (N + 1 - i);
		b[i - 1] += ar[i - 1];
	}
	for (int i = 0; i < N; i++)cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < N; i++)cout << b[i] << " ";
	cout << endl;
	return 0;
}
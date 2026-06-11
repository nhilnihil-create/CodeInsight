#include <iostream>
using namespace std;

int main() {
	int N, x;
	cin >> N >> x;
	int arr[N];
	for (int i = 0; i < N; i ++){
		cin >> arr[i];
	}
	long long step = 0;
	for (int i = 0; i < N - 1; i ++){
		if (arr[i] > x){
		  int gap = arr[i] - x;
		  arr[i] -= gap;
		  step += gap;
		}
		if (arr[i] + arr[i + 1] > x){
		  int dif = arr[i] + arr[i + 1] - x;
		  arr[i + 1] -= dif;
		  step += dif;
		}
	}
	cout << step << '\n';
}
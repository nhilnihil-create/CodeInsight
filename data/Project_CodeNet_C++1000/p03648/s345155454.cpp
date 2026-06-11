#include <iostream>
using namespace std;
 
int main(){
	int64_t k;
	cin >> k;
	int n = 50;
	cout << n << endl;
	int64_t a[n];
	for(int i = 0; i < n; i++) a[i] = i + k / n;
	for(int i = 0; i < k % n; i++){
		a[i] += n;
		for(int j = 0; j < 50; j++) if(i != j) a[j]--;
	}
	for(int i = 0; i < 50; i++) cout << a[i] << ' ';
	return 0;
}
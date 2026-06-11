#include <iostream>
using namespace std;
int main(){
	int N;
	
	int count=0;
	cin >> N;
	int* A = new int[N];
	for (int i = 0;i < N;i++) {
		cin >> A[i];
		if (A[i] % 2 == 1)
			count++;
	}
	if (count % 2 == 0) cout << "YES";
	else cout << "NO";
	

}
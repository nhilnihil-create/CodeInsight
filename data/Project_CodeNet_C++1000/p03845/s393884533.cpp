#include <iostream>
using namespace std;
int main(void){
	int n;
	cin >>n;
	int t[n];
	long sum=0;
	for(int i=0; i<n; i++){
		cin >> t[i];
		sum += t[i];
	}
	int m;
	cin >> m;
	while(m--){
		int p, x;
		cin >> p >> x;
		cout << sum + x - t[p-1] << "\n";
	}
}
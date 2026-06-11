#include <iostream>

using namespace std;

const int N = 1e6+10;
int a[N];

int main(){
	int n;
	cin >> n;
	while (n--){
		int t;
		cin >> t;
		a[t]++;
		a[t+1]++;
		a[t+2]++;
	}
	int max=0;
	for (int i=0;i<1e5+5;i++){
		if (a[i]>max) max=a[i];
	}
	cout << max << endl;
	
	return 0;
}
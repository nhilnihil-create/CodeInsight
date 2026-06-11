#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int x;
	int b[100001]={};
	for (int i=0; i<n; i++){
		cin>>x;
		if (x>0) b[x-1]++;
		b[x]++;
		b[x+1]++;
	}
	int z=0;
	for (int i=0; i<100001; i++){
		z = max(z, b[i]);
	}
	cout << z;
	

}
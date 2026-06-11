#include <bits/stdc++.h>
using namespace std;

int main () {
	int n[3], i;
	
	for(i=0; i<3; i++) {
		cin>>n[i];
	}
	
	sort(n,n+3);
	
	int sum=0;
	for(i=1; i<3; i++) {
		if(n[i] != n[i-1]) {
			sum++;
			
		}
	}
	
	cout<<sum+1<<endl;
	
}
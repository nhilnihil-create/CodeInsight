#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	long long n,x,i,m,memo;
	cin >> n >> x;
	m=2*n-1;
	if(x==1||x==m){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if(n==2){
		cout << "1" << endl;
		cout << "2" << endl;
		cout << "3" << endl;
		return 0;
	}
	memo=1;
	if(x!=2){
		for(i=1;i<=m;i++){
			if(i<n-1||i>n+2){
				if(memo==x-2) memo=x+2;
				cout << memo << endl;
				memo++;
			} else if(i==n-1){
				cout << x-1 << endl;
			} else if(i==n){
				cout << x+1 << endl;
			} else if(i==n+1){
				cout << x << endl;
			} else if(i==n+2){
				cout << x-2 << endl;
			}
		}
	} else {
		memo=5;
		for(i=1;i<=m;i++){
			if(i<n-1||i>n+2){
				cout << memo << endl;
				memo++;
			} else if(i==n-1){
				cout << "3" << endl;
			} else if(i==n){
				cout << "1" << endl;
			} else if(i==n+1){
				cout << "2" << endl;
			} else if(i==n+2){
				cout << "4" << endl;
			}
		}
	}
	return 0;
}
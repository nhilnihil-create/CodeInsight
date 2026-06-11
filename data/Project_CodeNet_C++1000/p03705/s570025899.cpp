#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,a,b;
	cin >> n >> a >> b;
	if(b<a) {cout << 0; return 0;}
	if(n==1 && a!=b) {cout << 0; return 0;}
	else if (n==1 && a==b) { cout << 1; return 0;}
	if(n==2) {cout << 1; return 0;}
	int changeable = n-2;
	long long count = 1;
	while(changeable){
		count+=b-a;
		changeable--;
		}
	cout << count;
}

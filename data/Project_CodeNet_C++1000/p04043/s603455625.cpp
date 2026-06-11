#include<bits/stdc++.h>
using namespace std;
int main () {
	int a,b,c;
	cin >> a >> b >> c;
	int n5 = ((a==5)?1:0) + ((b==5)?1:0) + ((c==5)?1:0);
	int n7 = ((a==7)?1:0) + ((b==7)?1:0) + ((c==7)?1:0);
	cout << ((n5==2) && (n7==1)?"YES":"NO");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long cal(long n, long x){
	long f;
	if(n>=0) f=n/x+1;
	if(n==-1) f=0;
	return f;
}

int main(){
	long a, b, x;
	cin >> a >> b >> x;
	long ans=cal(b, x)-cal(a-1, x);
	cout << ans << endl;
}

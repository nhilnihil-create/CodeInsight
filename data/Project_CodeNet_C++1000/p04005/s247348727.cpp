#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c;
	cin >> a >> b >> c;
	if(a*b*c%2==1){
		long long maxi = max(a,max(b,c));
		long long mini = min(a,min(b,c));
		long long midi = a+b+c - maxi - mini;
		cout << mini*midi;
	}
	else cout << 0;
		
}

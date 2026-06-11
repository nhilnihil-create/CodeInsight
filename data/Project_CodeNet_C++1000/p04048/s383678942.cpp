#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
int main(){
	cin >> n >> x;
	ans = n;
	n-=x;
	while (n){
		if (n < x)
		swap(n,x);
		ans += (n/x)*x*2;
		n = n%x;			
	}
	ans-=x;
	cout << ans;
}
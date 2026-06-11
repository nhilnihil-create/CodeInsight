#include <iostream>
#include <cstring>
#include <string>    
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a, b, c, d;

int main(){
	cin >> n >> a >> b >> c >> d;
	
	string ans = "NO";
	ll diff = abs(a-b); 
	for(ll i = 1; i <= n-1; i++){
		if(c*i-d*(n-1-i) <= diff && diff <= d*i-c*(n-1-i)){ans = "YES";}
	}
	
	cout << ans << endl;
	return 0;
}
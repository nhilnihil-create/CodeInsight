#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if (b==0) return a;
    else{
    	return gcd(b,a%b);
    }
}
 
int main() {
	ll a,b;
  	cin >> a >> b;
  	if((a+b)%3==0 || a%3 == 0 || b%3 == 0){
      cout << "Possible" << endl;
    }
  	else{
      cout << "Impossible" << endl;
    }
}
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
	ll a,b,c;
  	cin >> a >> b >> c;
  	if(0< -b+c && -b+c <= a){
      cout << "safe" << endl;
    }
  	else if(a+b>c){
      cout << "delicious" << endl;
    }
  	else{
      cout << "dangerous" << endl;
    }
  	
}
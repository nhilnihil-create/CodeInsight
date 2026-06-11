#include<bits/stdc++.h>

using ll = long long;
using namespace std;

bool f;
ll n, ans;

int main(){
	cin >> n;
	ans = (n/11);
	n -= ans*11;
	ans *= 2;
	while(n > 0){
		if(f){
			n -= 5;
			ans++;
		}else{
			n -= 6;
			ans++;
		}
	}
	cout << ans << endl;
}

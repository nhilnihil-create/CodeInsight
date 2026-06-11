#include <bits/stdc++.h>
using namespace std;
#define oo 1000000
#define mod 1000000007
const int N = 210;

long long solve(long long a,long long b){
	if(a > b) swap(a,b);
	if(a == 0) return 0;
	b *= 2 , a *= 2;
	if(b % a == 0){
		long long res = ((b / a) * a * 2 - a);
		return res / 2;
	}
	long long res = ((b / a) * a * 2)  + solve(b % a , a);
	return res / 2;
}

int main(){
	long long n , x;
	cin >> n >> x;
	long long ans = n + solve(x , n - x);
	cout << ans << endl;
	return 0;
}
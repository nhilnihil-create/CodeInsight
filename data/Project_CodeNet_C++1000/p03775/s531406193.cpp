#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	ll n;
	cin >> n;
	double a = sqrt(n);
	ll b = a;
	int M = 1e8;
	for(ll i = 1; i <= b; i++){
		if(n%i == 0){
			ll s1 = i;
			ll s2 = n/i;
			int c1= 1;
			int c2 = 1;
			while(s1 >= 10){
				s1 /= 10;
				c1++;
			}
			while(s2 >= 10){
				s2 /= 10;
				c2++;
			}
			M = min(M, max(c1, c2));
		}
	}
	cout << M  << endl;
}

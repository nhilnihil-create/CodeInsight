#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;

using namespace std;

void print2(ll a , ll b){cout << a << " : " << b << endl;}
void print3(ll a , ll b , ll c){cout << a << " : " << b << " : " << c << endl;}

const ll mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	map<int,int> mp;
	for(int i = n; i >= 2; i--){
		int x = i;
		for(int j = 2; j*j <= x; j++){
			if(x%j == 0){
				while(x%j == 0){
					x /= j;
					mp[j]++;
				}
			}
		}
		if(x > 1)mp[x]++;	
	}
	ll ans = 1;
	for(auto p : mp){
		ans *= (p.second + 1);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
 

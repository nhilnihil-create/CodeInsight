#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
	int n;
	cin >> n;
	ll a[300000]={};
	ll sum = 0;
	
	rep(i,n){
		cin >> a[i];
		sum += a[i];
	}

	ll dif = sum - 2*a[0];
	ll mi = abs(dif);

	FOR(i,1,n-1){
		dif -= 2*a[i];
		mi = min(abs(dif),mi);
	}

	cout << mi << endl;
	return 0;
}

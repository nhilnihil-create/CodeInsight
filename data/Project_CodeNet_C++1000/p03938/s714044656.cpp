#include <bits/stdc++.h>
//#include <atcoder/math>
//using namespace atcoder;
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;
ll  LINF = 1e18;

int main(){
	int n;cin >> n;
	vector<int> p(n),a(n),b(n),sum(n);
	rep(i,n) {
		int ind;cin >> ind;
		ind--;
		sum[ind] = INF - n + i; 	
	}
	
	rep(i,n) {
		a[i] = i+1;
		b[i] = sum[i]-a[i];
	}
	for(int i = 1;i < n;i++){
		if(a[i] <= a[i-1]) {
			b[i] -= (a[i-1]-a[i]+1);
			a[i] = a[i-1]+1;
		}
		if(b[i]>=b[i-1]){
			a[i] += b[i]-b[i-1]+1;
			b[i] = b[i-1]-1;
		}
	}
	rep(i,n) cout << a[i] << " ";
	cout << endl;
	rep(i,n) cout << b[i] << " ";
	cout << endl;

}
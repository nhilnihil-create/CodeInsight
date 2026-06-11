#include <bits/stdc++.h>
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

int main(){
	int n,k,x,y;cin >> n >> k >> x >> y;
	if(n<=k) cout << n*x << endl;
	else cout << k*x+(n-k)*y << endl;
} 
 
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
	int w,h,n;cin >> w >> h >> n;
	int u=h,d=0,l=0,r=w;
	rep(i,n){
		int a,y,x;cin >> x >> y >> a;
		if(a == 1) l = max(l,x);
		else if(a == 2) r = min(r,x);
		else if(a == 3) d = max(d,y);
		else u = min(u,y);
	}
	if(r-l > 0 && u-d > 0) cout << (r-l)*(u-d) << endl;
	else cout << 0 << endl;
	//printf("%d %d\n",r-l,u-d);
} 

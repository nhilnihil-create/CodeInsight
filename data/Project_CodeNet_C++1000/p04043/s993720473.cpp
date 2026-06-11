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
	int n5=0,n7=0;
	rep(i,3) {
		int a;cin >> a;
		if(a == 5) n5++;
		if(a == 7) n7++;
	}
	if(n5 == 2 && n7 == 1) cout <<"YES"<< endl;
	else cout << "NO"<< endl;

	
}
 
 
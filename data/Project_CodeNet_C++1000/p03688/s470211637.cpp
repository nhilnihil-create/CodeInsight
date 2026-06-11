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
	vector<int> hat(n);
	int mi=INF,ma=0;
	rep(i,n) {
		cin >> hat[i];
		mi = min(hat[i],mi);
		ma = max(hat[i],ma);
	}
	if(ma-mi>1) {
		cout << "No"<< endl;
		return 0;
	}
	int nmi = 0,nma = 0;
	rep(i,n){
		if(hat[i]==mi) nmi++;
		else nma++;
	}
	if(mi==ma){
		if(1<=mi && mi <= n/2) cout << "Yes" << endl;
		else if(mi == n-1) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	if(nmi <= mi && ma <= nmi+nma/2) cout << "Yes" << endl;
	else cout << "No" << endl;	
}
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
	int n;cin >> n;
	vector<int> a(n);
	int tot = 0;
	rep(i,n){
		cin >> a[i];
		tot += a[i];
	}
	int av1 = tot/n;
	int av2 = tot/n+1;
	int sum1=0,sum2=0;
	rep(i,n){
		sum1 += (a[i]-av1)*(a[i]-av1);
		sum2 += (a[i]-av2)*(a[i]-av2);
	}
	cout << min(sum1,sum2) << endl;

} 
 
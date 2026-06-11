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
	double x;
	cin >> x;

	cout << (ll)ceil((-1.0 + sqrt(1.0 + 8.0 * x))/2.0) << endl;
	}

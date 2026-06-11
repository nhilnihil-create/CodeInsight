#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll a,b,x;
	cin >> a >> b >> x;
	cout << b/x - a/x +((a%x==0)?1:0) << endl;
}
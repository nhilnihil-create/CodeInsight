#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int ans;
	if(c >= b) ans = 0;
	if(c >= a && d > b) ans = b-c;
	if(c >= a && d <= b) ans = d-c;
	if(d <= a) ans = 0;
	if(c <= a && d >= b) ans = b-a;
	if(c <= a && d < b && d >= a) ans = d-a;
    if(ans < 0) ans = 0;
	cout << ans << endl;
}
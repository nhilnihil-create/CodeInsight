#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL ans, a, b, c;

int main() {
    ans = 1e18;
	cin>>a>>b>>c;
	ans = min(ans, a*c*(b%2));
	ans = min(ans, a*b*(c%2));
	ans = min(ans, b*c*(a%2));
	cout<<ans<<endl;
	return 0;
}
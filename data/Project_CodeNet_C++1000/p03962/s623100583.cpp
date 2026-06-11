#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int a[3];rep(i,3)cin>>a[i];
    sort(a,a+3);
    int ans = 1;
    rep(i,2)if(a[i+1]!=a[i])++ans;
    cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int k,t;cin>>k>>t;
    int a[t];rep(i,t)cin>>a[i];
    sort(a,a+t,greater<int>());
    cout<<max(a[0]*2-1-k,0)<<endl;
	return 0;
}
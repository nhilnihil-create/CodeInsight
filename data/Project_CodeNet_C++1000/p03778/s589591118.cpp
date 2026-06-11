#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int w,a,b;cin>>w>>a>>b;
    int ans;
    if(a>b)ans=a-b;
    else ans = b-a;
    cout<<max(0,ans-w)<<endl;
	return 0;
}
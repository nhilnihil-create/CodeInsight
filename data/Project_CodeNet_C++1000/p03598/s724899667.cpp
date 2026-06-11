#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,k;cin>>n>>k;
    int ans = 0;
    rep(i,n){
        int tmp;cin>>tmp;
        ans += 2 * min(abs(tmp), abs(k-tmp));
    }
    cout<<ans<<endl;
	return 0;
}
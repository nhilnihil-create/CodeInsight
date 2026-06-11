#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_kaisetsu
int MOD = 1000000007;

int main() {
    int n;cin>>n;
    int a[1001];
    rep(i,1001)a[i]=1;  
    for(int i=2;i<=n;++i){
            int k=i;
            int j=2;
            while(k>1){
            while(k%j==0){
                ++a[j];
                k/=j;
            }
            ++j;
        }
    }
    ll ans = 1;
    rep(i,1001)if(a[i]!=0)ans=(ans*a[i])%MOD;
    cout<<ans<<endl;
	return 0;
}
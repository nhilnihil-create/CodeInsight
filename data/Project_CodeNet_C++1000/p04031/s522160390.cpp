#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

 
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int ans=MOD;
    for(int i=-100;i<=100;i++){
        int sum=0;
        rep(j,n){
            sum+=pow(a[j]-i,2);
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    string s;
    cin>>s;
    int N=s.length();
    ll ans=0;
    for(int bit=0;bit<(1<<(N-1));bit++){ //bit全探索
        ll tmp=0;
        rep(i,N-1){
            tmp*=10;
            tmp+=s[i]-'0';
            if(bit & (1<<i)){
                ans+=tmp;
                tmp=0;
            }
        }
        tmp*=10;
        tmp+=s.back()-'0';
        ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}
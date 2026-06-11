#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
#define PI 3.1415926535897932384626433832795028841971693993
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n,ans=0;
    cin>>n;
    map<ll,ll> dat;
    rep(i,n){
        int a;
        cin>>a;
        if(dat[a]==0){
            ans++;
            dat[a]++;
        }
        else{
            ans--;
            dat.erase(a);
        }
    }
    cout<<ans;
}
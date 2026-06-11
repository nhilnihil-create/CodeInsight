#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x[100010];

int main(){
    int n; ll k;
    cin>>n>>k;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        x[a]+=b;
    }
    ll cnt=0;
    rep(i,100010){
        cnt+=x[i];
        if(cnt>=k){
            cout<<i<<endl;
            return 0;
        }
    }
}
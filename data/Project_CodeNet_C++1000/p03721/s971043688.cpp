#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<vector<int>>a(n,vector<int>(2));
    vector<ll>v(n+1,0);
    rep(i,0,n){
        cin>>a[i][0]>>a[i][1];
    }
    sort(all(a));
    rep(i,0,n){
        v.at(i+1)=a[i][1]+v.at(i);
    }
    rep(i,0,n+1){
        if(k<=v.at(i)){
            cout<<a[i-1][0]<<endl;
            return 0;
        }
    }
return 0;
}
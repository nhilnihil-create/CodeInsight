#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){ 
    int n,p,c=0,b=0;cin>>n>>p;
    vector<int>a(n);
    ll sum = 0;
    int ok=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==1)ok=1;
        sum+=a[i];
    }
    int num;
    ll ans=0;
    if(ok){
        ans = pow(2,n-1);
    }else{
        if(p==0)ans=pow(2,n);
        else ans =0;
    }
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    bool flag=true;
    int odd=0;
    rep(i,n){
        if(a[i]%2==1)odd++;
    }
    flag=odd%2==0;
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
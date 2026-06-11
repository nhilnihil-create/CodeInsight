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
void calc(vector<int>& a,int i,int n){
    rep(j,n){
        if(j==i)a[i]+=n;
        else a[j]-=1;
    }
}
signed main(){
    int k;cin>>k;
    int n=50;
    vector<int> a(n,n-1);
    int buf=k/n;
    rep(i,n){
        a[i]+=buf;
    }
    k%=n;
    rep(i,k){
        calc(a,i,n);
    }
    cout<<n<<endl;
    rep(i,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
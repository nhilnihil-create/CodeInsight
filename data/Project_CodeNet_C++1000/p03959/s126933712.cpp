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
int MOD=1000000007;
signed main(){
    int n;cin>>n;
    vector<int> t(n);
    rep(i,n)cin>>t[i];
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int res=1;
    int max=0;int max2=0;
    rep(i,n){
        if(t[i]==t[n-1]){
            max=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==a[0]){
            max2=i;
            break;
        }
    }
    if(t[n-1]!=a[0])res=0;
    int left=1;int right=1;
    int last=t[0];
    rep1(i,max){
        if(t[i]==last){
            left*=last;
            left%=MOD;
        }
        last=t[i];
    }
    last=a[n-1];
    for(int i=n-2;i>=max2;i--){
        if(a[i]==last){
            right*=last;
            right%=MOD;
        }
        last=a[i];
    }
    for(int i=max;i<=max2;i++){
        if(i!=max&&i!=max2){
            res*=t[max];
            res%=MOD;
        }
    }
    res*=left;
    res%=MOD;
    res*=right;
    res%=MOD;
    if(max>max2)res=0;
    cout<<res<<endl;
    return 0;
}
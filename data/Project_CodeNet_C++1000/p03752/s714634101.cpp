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
int MOD=1000000007;int inf=MOD*MOD;
int n,k;
int a[20];
int calc(vector<bool> const& status){
    int num=0;
    rep(i,n){
        if(status[i])num++;
    }
    if(num<k)return inf;
    int res=0;
    int last=a[0];
    rep1(i,n-1){
        if(status[i]){
            res+=max((int)0,last-a[i]+1);
            last=max(last+1,a[i]);
        }
        if(last<a[i]){
            last=a[i];
        }
    }
    return res;
}
int solve(vector<bool> status,int cur){
    if(cur==n)return calc(status);
    else{
        int res=solve(status,cur+1);
        status[cur]=true;
        res=min(res,solve(status,cur+1));
        return res;
    }
}
signed main(){
    cin>>n>>k;
    rep(i,n)cin>>a[i];
    vector<bool> status(n,false);
    status[0]=true;
    int res=solve(status,1);
    cout<<res<<endl;
    return 0;
}
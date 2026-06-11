#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[100001];
ll d[200100],t[200100];
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,n){
        cin>>a[i];
    }
    ll sum=0;
    rep(i,n-1){
        int l=a[i],r=a[i+1];
        if(r<l) r+=m;
        sum+=r-l;
        ++d[l+2];
        --d[r+1];
        t[r+1]-=r-l-1;
    }
    FOR(i,1,2*m+1){
        d[i]+=d[i-1];
        t[i]+=d[i]+t[i-1];
    }
    ll mn=100010001000100010;
    FOR(i,1,m+1) mn=min(mn,sum-t[i]-t[i+m]);
    cout<<mn<<endl;
    return 0;
}
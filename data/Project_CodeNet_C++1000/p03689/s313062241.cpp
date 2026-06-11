#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[501],sum[501];
int main(){
    int h,w,y,x;
    cin>>h>>w>>y>>x;
    if(h%y==0&&w%x==0){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    int cur=10000;
    if(w%x!=0){
        FOR(i,1,w+1){
            if(i-x<0) sum[i]=cur;
            else cur=sum[i-x]-1,sum[i]=cur;
        }
        FOR(i,1,w+1) a[i-1]=sum[i]-sum[i-1];
        rep(i,h){
            rep(j,w) cout<<a[j]<<" ";
            cout<<endl;
        }
    }
    else{
        FOR(i,1,h+1){
            if(i-y<0) sum[i]=cur;
            else cur=sum[i-y]-1,sum[i]=cur;
        }
        FOR(i,1,h+1) a[i-1]=sum[i]-sum[i-1];
        rep(i,h){
            rep(j,w) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
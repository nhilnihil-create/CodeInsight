#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
#define all(L) L.begin(),L.end()
using ll=long long;

int N,M;
int X[100],Y[100],h[100];

void gcl(int& x,int& y){
    if(x<y) swap(x,y);
    while(y>0){
        int t=x%y;
        x=y;
        y=t;
    }
    return;
}


int main(){
    int n;cin>>n;
    vector<int> p;
    int i=0,j;
    for(j=2;j<=n;j++){
        bool flag=true;
        for(int k=2;k<j;k++){
            if(j%k==0){
                flag=false;break;
            }
        }
        if(flag){
            p.push_back(j);
            i++;
        }
    }
    vector<vector<ll> > v(n+1,vector<ll>(n+1,0));
    for(int i=1;i<=n;i++){
        int u=i;
        for(int j=0;j<p.size();j++){
            int t=0;
            while(u%p[j]==0){
                t++;
                u/=p[j];
            }
            v[i][p[j]]+=t;
        }
        for(int j=0;j<=n;j++) v[i][j]+=v[i-1][j];
    }

    ll ans=1;
    for(int i=0;i<=n;i++){
        ans*=(v[n][i]+1);
        ans%=1000000007;
    }
    cout<<ans<<endl;
}
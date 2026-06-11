#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll tab[2*m+1]={};
    ll ans=0;
    for(int i=0;i<n-1;i++){
        int prev=a[i]-1;
        int next=a[i+1]-1;
        if(prev>next)next+=m;
        ans+=next-prev;
        tab[prev+2]++;
        tab[next+1]--;
    }
    for(int i=1;i<2*m;i++){
        tab[i]+=tab[i-1];
    }
    for(int i=0;i<n-1;i++){
        int prev=a[i]-1;
        int next=a[i+1]-1;
        if(prev>next)next+=m;
        if(prev+2<=next)tab[next+1]-=next-prev-1;
    }
    for(int i=1;i<2*m;i++){
        tab[i]+=tab[i-1];
    }
    ll mx=-1;
    for(int x=0;x<m;x++){
        mx=max(mx,tab[x]+tab[x+m]);
    }
    ans-=mx;
    cout<<ans<<endl;
}
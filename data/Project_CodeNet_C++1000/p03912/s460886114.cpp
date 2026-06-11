#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int f(int p,int n){
    if(n%2!=0)n--;
    return min(n,p*2)/2;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> num(m,0);
    vector<int> sm(m,0);
    
    map<int,int> mp;
    
    rep(i,n){
        int x;
        cin>>x;
        num[ x%m ]++;
        mp[x]++;
    }
    
    for(auto &e:mp){
        sm[e.first%m]+=e.second/2;
    }
    
    
    
//    rep(i,m)cout<<num[i]<<" ";cout<<endl;
//    rep(i,m)cout<<sm [i]<<" ";cout<<endl;
    
    
    ll ans=0;
    ans+=num[0]/2;
    num[0]-=num[0];
    
    int c=1;

    while(1){
        if(c==m-c){
            ans+=num[c]/2;
            num[c]-=num[c];
            break;
        }
        if(c>m-c)break;
        ans+=min(num[c],num[m-c]);
        int mn = min(num[c],num[m-c]);
        num[c] -=mn;
        num[m-c] -= mn;
        c++;
    }

    rep(i,m){
        if(sm[i]!=0){
            ans+=f(sm[i],num[i]);
        }
    }
    cout<<ans<<endl;
}
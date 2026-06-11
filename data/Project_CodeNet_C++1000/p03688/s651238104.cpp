#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define N 3000000
 
using namespace std;

main(){
    int n;
    cin>>n;
    int a[N];
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    if(a[0]+1<a[n-1]){
        cout<<"No"; return 0;
    }
    if(a[0]==a[n-1]){
        if(a[0]==n-1||a[0]<=n/2) {cout<<"Yes"; return 0;}
        cout<<"No"; return 0;
    }
    int s=0,t=0;
    rep(i,n){
        if(a[i]==a[0])s++;
        else t++;
    }
    if(a[0]+1<=s+t/2&&a[0]+1>s){
        cout<<"Yes"; return 0;
    }
    cout<<"No"; return 0;
    
    return 0;
}

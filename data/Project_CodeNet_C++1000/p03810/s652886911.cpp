#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define N 300000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

int gcd(int a,int b){
    if(a>b){
        return gcd(b,a);
    }
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
main(){
    int n;
    ll int a[N];
    cin>>n;
    ll int sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(n==1){
        cout<<"Second";
        return 0;
    }
    if(n%2==0){
        if(sum%2) cout<<"First";
        else cout<<"Second";
        return 0;
    }
    if(n%2&&sum%2==0){
        cout<<"First";
        return 0;
    }
    int turn=0;
    while(1){
        int isodd=0;
        bool flag=false;
        rep(i,n){
            if(a[i]==1) {isodd=2;}
            if(a[i]%2==1){
                isodd++;
                a[i]=a[i]-1;
            }
        }
        if(isodd>1) break;
        int g=a[0];
        rep(i,n){
            g=gcd(g,a[i]);
        }
        rep(i,n){
            a[i]/=g;
        }
        ll int ssum=0;
        rep(i,n){
            ssum+=a[i];
        }
        if(ssum%2==0) break;
        turn++;
    }
    if(turn%2==1){
        cout<<"First";
    }
    else cout<<"Second";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX/10
#define rep(i,n) for(int i=0;i<n;i++)
#define krep(i,k,n,m) for(int i=k;i<n;i+=m)
#define erep(i,k,n) for(int i=k;i<n;i++)
#define mod 1000000007
//最大公約数
int gcd(int s,int b){
    if(b==0)return s;
    return gcd(b,s%b);
}
signed main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0,kai=1;
    rep(i,n-1){
        if(a[i]==a[i+1]){
            ans++;
        }
    }
    rep(i,n-1){
        if(a[i]!=a[i+1]){
            kai++;
        }
    }
    if(ans%2==0){
        cout<<kai<<endl;
    }
    else{
        cout<<kai-1<<endl;
    }
}

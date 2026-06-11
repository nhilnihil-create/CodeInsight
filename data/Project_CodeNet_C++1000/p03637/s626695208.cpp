#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n) cin>>a[i];
    int cnf=0;
    int cnt=0;
    rep(i,n){
        if(a[i]%4==0)cnf+=1;
        if(a[i]%2==0)cnt+=1;
    }
    cnt-=cnf;
    if(cnt>=n-cnf*2 | cnf>=(n/2))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
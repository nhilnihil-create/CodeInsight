#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    bool u=false,d=false;
    int ans=0;
    rep(i,n-1){
        if(!u&!d){
            if(a[i]<a[i+1])u=true;
            else if(a[i]>a[i+1])d=true;
        }
        else if(u){
            if(a[i]>a[i+1])ans++,u=false;
        }
        else if(d){
            if(a[i]<a[i+1])ans++,d=false;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}
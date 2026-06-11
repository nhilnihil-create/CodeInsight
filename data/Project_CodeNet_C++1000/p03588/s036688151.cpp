#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    int mx=0,cnt=0;
    rep(i,n){
        int a,b; cin>>a>>b;
        if(mx<a){
            mx=a;
            cnt=b;
        }
    }
    cout<<mx+cnt<<endl;
}
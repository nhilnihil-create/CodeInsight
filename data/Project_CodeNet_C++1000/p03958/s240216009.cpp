#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int k,t;
    cin>>k>>t;
    vector<int>a(t);
    int sum=0,mx=0;
    rep(i,t){
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    sum-=mx;
    if(sum-1>=mx)cout<<0<<endl;
    else cout<<mx-sum-1<<endl;
}
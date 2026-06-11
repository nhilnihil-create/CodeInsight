#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll n,l,a[100000];

int main(){
    cin>>n>>l;
    rep(i,n)cin>>a[i];
    int x=0;
    rep(i,n-1)if(a[i]+a[i+1]>=l)x=i+1;
    if(x==0){
        cout<<"Impossible\n";
        return 0;
    }
    cout<<"Possible\n";
    for(int i=1;i<x;i++)cout<<i<<endl;
    for(int i=n-1;i>=x;i--)cout<<i<<endl;
}
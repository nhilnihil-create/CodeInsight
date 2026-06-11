#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxv=0;
    int x=0;
    rep(i,n){
        if(s[i]=='I') x+=1;
        else x-=1;
        maxv=max(maxv,x);
    }

    cout<<maxv<<"\n";
    return 0;
}
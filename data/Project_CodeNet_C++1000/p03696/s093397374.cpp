#include<bits/stdc++.h>
using namespace std;
#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)

int main(){
    int n;cin>>n;
    string ss;cin>>ss;
    int l=0,r=0;
    int tot=0;
    rep(i,n){
        if(ss[i]=='(')tot++;
        else{
            if(tot==0)l++;
            else tot--;
        }
    }
    tot=0;
    for(int i=n-1;i>=0;--i){
        if(ss[i]==')')tot++;
        else{
            if(tot==0)r++;
            else tot--;
        }
    }

    rep(i,l)cout<<'(';
    cout<<ss;
    rep(i,r)cout<<')';
    cout<<endl;
    return 0;
}

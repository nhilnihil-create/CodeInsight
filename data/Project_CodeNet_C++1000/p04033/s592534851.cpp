#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t a,b; cin>>a>>b;
    if(a*b<=0) cout<<"Zero"<<endl;
    else if(a>0 && b>0) cout<<"Positive"<<endl;
    else{
        if((abs(a-b)+1)%2) cout<<"Negative"<<endl;
        else cout<<"Positive"<<endl;
    }
}
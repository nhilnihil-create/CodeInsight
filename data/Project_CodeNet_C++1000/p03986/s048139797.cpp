#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string X; cin>>X;

    int n=0,ans=0;
    rep(i,0,X.size()){
        char c=X.at(i);
        if(c=='S') n++;
        else{
            if(n>0){
                ans++;
                n--;
            }
        }
    }

    ans=X.size()-2*ans;
    cout<<ans<<endl;
}
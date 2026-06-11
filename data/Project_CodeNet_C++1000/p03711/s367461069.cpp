#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

using ll=long long;

int main(){
    int x[2];
    cin>>x[0]>>x[1];
    int g[2];
    rep(i,2){
        if(x[i]==2) g[i]=3;
        else if(x[i]==4 || x[i]==6 || x[i]==9 || x[i]==11) g[i]=2;
        else g[i]=1;
    }
    if(g[0]==g[1]) cout<<"Yes";
    else cout<<"No";
    cout<<endl;

   return 0;
}
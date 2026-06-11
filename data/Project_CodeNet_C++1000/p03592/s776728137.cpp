#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    bool ok=false;
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=m; ++j){
            if(i*j+(n-i)*(m-j)==k)ok=true;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}
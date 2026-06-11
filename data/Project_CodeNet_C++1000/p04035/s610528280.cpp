#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,l;
    cin>>n>>l;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int rope=0;
    bool ok=false;
    rep(i,n-1){
        if(a[i]+a[i+1]>=l){
            ok=true;
            rope=i+1;
        }
    }
    if(!ok)cout<<"Impossible"<<endl;
    else{
        cout<<"Possible"<<endl;
        for(int i=1; i<=n-1; ++i){
            if(i<rope)cout<<i<<endl;
        }
        for(int i=n-1; i>=0; --i){
            if(i>rope)cout<<i<<endl;
        }
        cout<<rope<<endl;
    }
}
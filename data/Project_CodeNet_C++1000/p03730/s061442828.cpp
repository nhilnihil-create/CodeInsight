#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int a,b,c;

int main(){
    cin>>a>>b>>c;
    bool flag=false;
    int ans;
    for(int i=1;i<=b;i++){
            if((i*a)%b==c){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF (INT_MAX)
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    int ans=INF;
    for(int i=0;i<=n;i++){
        string ss=s.substr(n-i,i);
        string tt=t.substr(0,i);
        if(ss==tt){
            ans=min(ans,n*2-i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;


int32_t main()
{
    int n,m;
    cin>>n>>m;
    string s[n],t[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        cin>>t[i];
    }
    rep(i,0,n-m+1)rep(j,0,n-m+1){
        bool flg=1;
        rep(h,0,m)rep(w,0,m){
            if(s[i+h][j+w]!=t[h][w])flg=0;
        }
        if(flg){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";

    return 0;
}

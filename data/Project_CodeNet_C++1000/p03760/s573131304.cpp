#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9+7;

int32_t main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<min(n,m);i++){
        cout<<s[i]<<t[i];
    }
    if(n>m)cout<<s[n-1]<<endl;
    else if(n<m)cout<<t[m-1]<<endl;
    return 0;
}

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
    if(n>m){cout<<"GREATER\n";return 0;}
    else if(n<m){cout<<"LESS\n";return 0;}
    else{
    int p=0;
        while(s[p]==t[p] && p<n)p++;
    if(p==n)puts("EQUAL");
    else if(s[p]>t[p])puts("GREATER");
    else puts("LESS");
    }

    return 0;
}

#include <bits/stdc++.h> 
using namespace std; 
#define int long long
# define pii pair<char,int>
const int maxn=1e6+5;
signed main() { 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a==1 && b==1)cout<<"Draw";
    else if(a==1)cout<<"Alice";
    else if(b==1)cout<<"Bob";
    else
    {
        cout<<(a>b?"Alice":(a==b)?"Draw":"Bob");
    }
    return 0;
}
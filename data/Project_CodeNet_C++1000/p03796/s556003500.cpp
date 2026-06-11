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
    int n;
    cin>>n;
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
        f%=mod;
    }
    cout<<f<<endl;

    return 0;
}

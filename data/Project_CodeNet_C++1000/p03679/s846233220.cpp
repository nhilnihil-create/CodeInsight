#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
using namespace std;

main()
{
        long x,a,b; cin>>x>>a>>b;
        string ans;
        if(a-b>=0)ans="delicious";
        else if(b-a<=x)ans="safe";
        else ans="dangerous";
        cout<<ans<<endl;
}
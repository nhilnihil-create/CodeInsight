#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define all(v) (v).begin(),(v).end()
#define mod 1e9+7

using namespace std;
using vi = vector<int>;
using vl = vector<long>;
using P = pair<int,int>;

main()
{
        int a,b; cin>>a>>b;
        bool flag=false;
        if(a%3==0)flag=true;
        if(b%3==0)flag=true;
        if((a+b)%3==0)flag=true;
        cout<<(flag?"Possible":"Impossible")<<endl;
}
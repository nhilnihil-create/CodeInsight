#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    map<int,int>mp;
    mp[1]=1;
    mp[3]=1;
    mp[5]=1;
    mp[7]=1;
    mp[8]=1;
    mp[10]=1;
    mp[12]=1;
    mp[4]=2;
    mp[6]=2;
    mp[9]=2;
    mp[11]=2;
    mp[2]=3;
   int a,b;
   cin>>a>>b;
   if(mp[a]==mp[b])
    cout<<"Yes"<<endl;
   else
    cout<<"No"<<endl;
    return 0;
}

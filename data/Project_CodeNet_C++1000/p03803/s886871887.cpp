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
    int cnt=1;
    for(int i=2;i<=13;i++)
        mp[i]=cnt++;
    mp[1]=cnt;
    int a,b;
    cin>>a>>b;
    if(mp[a]>mp[b])
        cout<<"Alice"<<endl;
    else if(mp[b]>mp[a])
        cout<<"Bob"<<endl;
    else
        cout<<"Draw"<<endl;

    return 0;
}

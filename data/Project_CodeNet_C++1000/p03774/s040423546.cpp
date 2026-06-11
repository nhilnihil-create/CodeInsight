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
int dist(int a,int b,int c,int d)
{
    return abs(a-c)+abs(b-d);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> >x,y;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        x.push_back({a,b});
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        y.push_back({a,b});
    }
    for(int i=0; i<n; i++)
    {
        int mn=INT_MAX,pos=0;
        for(int j=0; j<m; j++)
        {
            int cur=dist(x[i].first,x[i].second,y[j].first,y[j].second);
            if(cur<mn)
            {
                mn=cur;
                pos=j;
            }
        }
        cout<<pos+1<<endl;
    }

    return 0;
}

/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int n,k;
vector<int> v[2020];
int fun(int node, int centre, int dist)
{
    int temp=1;
    if(dist)
    {
        for(int i=0;i<(int)v[node].size();++i)
        {
            if(v[node][i]!=centre)
                temp+=fun(v[node][i],node,dist-1);
        }
    }
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=0,y=0,res=0;
    cin>>n>>k;
    for(int i=0;i+1<n;++i)
    {
        cin>>x>>y;
        --x;--y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if(k&1)
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<(int)v[i].size();++j)
                res=max(res,fun(i,v[i][j],k/2)+fun(v[i][j],i,k/2));
    }
    else
    {
        for(int i=0;i<n;++i)
            res=max(res,fun(i,i,k/2));
    }
    cout<<(n-res)<<endl;
}
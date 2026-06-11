#include<iostream>
#include<cstdio>
#include<map>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 2e5+7;
int a[maxn];
int p[maxn],q[maxn],r[maxn];
int found1(int x)
{
    return x==p[x]?x : p[x] = found1(p[x]);
}
int found2(int x)
{
    return x==q[x]?x : q[x] = found2(q[x]);
}
int main()
{
    int n,l,k;
    cin >> n >> k >> l;
    int a,b;
    for(int i = 0; i < n; i ++)
    {
        p[i] = i;
        q[i] = i;
    }
    for(int i = 0; i < k; i ++)
    {
        scanf("%d%d",&a,&b);
        int x = found1(a),y = found1(b);
        if(x!=y)
        {
            p[x] = y;
        }
    }
    for(int i = 0; i < l; i ++)
    {
        scanf("%d%d",&a,&b);
        int x = found2(a),y = found2(b);
        if(x!=y)
        {
            q[x] = y;
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        found1(i);
        found2(i);
    }
    map<pair<int,int>,int>mp;
    for(int i = 1; i <= n; i ++)
    {
        mp[make_pair(p[i],q[i])]++;
    }
    for(int i = 1; i <= n; i ++)
    {
        cout << mp[make_pair(p[i],q[i])] << " ";
    }
    cout <<endl;
    return 0;
}

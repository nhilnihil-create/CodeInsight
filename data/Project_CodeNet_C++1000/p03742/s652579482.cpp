#include<bits/stdc++.h>
#define int long long
using namespace std;
 

bool comp1(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
    return a.first.first<b.first.first;
}
bool comp2(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
    return a.first.second<b.first.second;
}

int parent[100005];
int sz[100005];
int find_parent(int ver)
{
    if(ver==parent[ver])
        return ver;
    return parent[ver]=find_parent(parent[ver]);
}

bool merge(int a,int b)
{
    a=find_parent(a);
    b=find_parent(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
            swap(a,b);
        sz[a]+=sz[b];
        parent[b]=a;
        return true;
    }
    return false;
}

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    int x,y;
    cin>>x>>y;
    if(abs(x-y)>1)
        cout<<"Alice";
    else
        cout<<"Brown";
}
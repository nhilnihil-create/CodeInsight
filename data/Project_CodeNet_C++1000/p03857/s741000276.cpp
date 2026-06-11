#include<iostream>
#include<map>
using namespace std;
struct rode{int x,y;}a[100001];
struct subway{int x,y;}b[100001];
int rtree[200100],stree[200100];
map< pair<int,int>,int>  num;
int findrroot(int root)
{
    int start,t;
    start=root;
    while(root!=rtree[root])
        root=rtree[root];
    while(start!=root)
    {
        t=rtree[start];
        rtree[start]=root;
        start=t;
    }
    return root;
}
int findsroot(int root)
{
    int start,t;
    start=root;
    while(root!=stree[root])
        root=stree[root];
    while(start!=root)
    {
        t=stree[start];
        stree[start]=root;
        start=t;
    }
    return root;
}
int main()
{
    int N,K,L;
    int root1,root2;
    cin>>N>>K>>L;
    for(int i=1;i<=K;i++)
        cin>>a[i].x>>a[i].y;
    for(int i=1;i<=L;i++)
        cin>>b[i].x>>b[i].y;
    for(int i=1;i<=N;i++)
    {
        rtree[i]=i;
        stree[i]=i;
    }
    for(int i=1;i<=K;i++)
    {
        root1=findrroot(a[i].x);
        root2=findrroot(a[i].y);
        if(root1!=root2)
            rtree[root2]=root1;
        //for(int i=1;i<=N;i++)
//cout<<stree[i]<<" ";
        //cout<<endl;
    }
    for(int i=1;i<=L;i++)
    {
        root1=findsroot(b[i].x);
        root2=findsroot(b[i].y);
        if(root1!=root2)
            stree[root2]=root1;
    }
    for(int i=1;i<=N;i++)
    {
        findrroot(i);
        findsroot(i);
    }
    for(int i=1;i<=N;i++)
    {
        num[make_pair(rtree[i],stree[i])]++;
    }
    for(int i=1;i<=N;i++)
        cout<<num[make_pair(rtree[i],stree[i])]<<" ";
    return 0;
}

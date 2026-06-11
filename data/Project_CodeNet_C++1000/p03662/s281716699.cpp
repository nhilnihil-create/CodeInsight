#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=100100;
vector<int> head[N];
int n,l[N],len;
pair<bool,int> dfs(int x,int fa,int c)
{
    int size=1;
    bool f=false;
    for(int i=0;i<head[x].size();++i)
    {
        int y=head[x][i];
        pair<bool,int> t;
        if(y!=fa)
        {
            t=dfs(y,x,c+1);
            f=f||t.first;
            if(!t.first) size+=t.second;
        }
    }
    if(f||x==n) 
    {
        if(x==n) len=c;
        l[c]=size-1;
        return make_pair(true,size);
    }
    else return make_pair(false,size);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        head[x].push_back(y);
        head[y].push_back(x);
    }
    dfs(1,0,1);
    int a=0,b=0;
    for(int i=1;i<=(1+len)>>1;++i)
        a+=l[i];
    for(int i=(3+len)>>1;i<=len;++i)
        b+=l[i];
    if(a>b||(a==b&&len%2==1))
        cout<<"Fennec"<<endl;
    else
        cout<<"Snuke"<<endl;
    return 0;
}
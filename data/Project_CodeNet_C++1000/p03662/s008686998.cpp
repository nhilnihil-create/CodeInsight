#include<iostream>
#include<vector>
#define N 100010
using namespace std;
vector<int> V[N];
int n;
int dis_from_1[N];
int dis_from_n[N];
void DFS(int start,int pre,bool mode)
{
    if(mode)
    {
        dis_from_1[start]=dis_from_1[pre]+1;
    }
    else
    {
        dis_from_n[start]=dis_from_n[pre]+1;
    }
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(next!=pre)
        {
            DFS(next,start,mode);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) V[i].clear();
        int a,b;
        for(int i=1;i<=n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dis_from_1[0]=-1;
        DFS(1,0,true);
        dis_from_n[0]=-1;
        DFS(n,0,false);
        int F_point=0;
        int S_point=0;
        for(int i=1;i<=n;i++)
        {
            if(dis_from_1[i]<=dis_from_n[i]) F_point++;
            else S_point++;
        }
        //cout<<"F:"<<F_point<<"  S:"<<S_point<<endl;
        if(F_point>S_point) cout<<"Fennec"<<endl;
        else cout<<"Snuke"<<endl;
    }
}
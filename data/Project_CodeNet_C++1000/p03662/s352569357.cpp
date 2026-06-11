#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define N 100010
vector<int> V[N];
int n;
int parent[N];//记录父结点
int dis_from_1[N];
void DFS(int start,int pre)
{
    dis_from_1[start]=dis_from_1[pre]+1;
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        if(next!=pre) 
        {
            parent[next]=start;//确定父结点
            DFS(next,start);
        }
    }
}
int S_count;
void DFS_for_count(int start,int pre)
{
    S_count++;
    //cout<<"start: "<<start<<" pre:"<<pre<<endl;
    for(int i=0;i<V[start].size();i++)
    {
        int next=V[start][i];
        //cout<<"next:"<<next<<endl;
        if(next!=pre) 
        {
            DFS_for_count(next,start);
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
        DFS(1,0);
        int k=dis_from_1[n]-1;//路径点数
        int cur_point=n;
        int cnt=0;//S
        int now_parent=parent[n];
        while(1)
        {
            if(cnt>=k-ceil(k/2.0)||now_parent==1)   break; //找到分界点或强制退出
            cur_point=now_parent;
            now_parent=parent[cur_point];
            cnt++;
        }
        //cout<<"cur_point:"<<cur_point<<"now_parent:"<<now_parent<<endl;
        S_count=0;
        DFS_for_count(cur_point,now_parent);
        //cout<<"F:"<<n-S_count<<endl;
        //cout<<"S:"<<S_count<<endl;
        if(n>2*S_count) cout<<"Fennec"<<endl;
        else cout<<"Snuke"<<endl;
    }
}
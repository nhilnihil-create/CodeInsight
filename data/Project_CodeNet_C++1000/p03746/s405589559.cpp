#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
using namespace std;
const int nmax=100005;
deque<int> dq;
vector<int> v[nmax];
int in[nmax];
int n,i,a,b,m;
int bag_a,bag_b,oka,okb,st,dr;
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dq.push_back(1);in[1]=1;
    while((!oka)||(!okb))
    {
        st=dq.front();dr=dq.back();
        bag_a=bag_b=0;
        if(!oka)
        for(int i=0;i<v[st].size();i++)
            if(!in[v[st][i]])
        {
            bag_a=v[st][i];
        }
        if(!okb)
        for(int i=0;i<v[dr].size();i++)
            if(!in[v[dr][i]])
        {
            bag_b=v[dr][i];
        }
        if(!bag_a) oka=1;
        else dq.push_front(bag_a);
        if(!bag_b) okb=1;
        else if(bag_a!=bag_b)dq.push_back(bag_b);
        in[bag_a]=in[bag_b]=1;
    }
    cout<<dq.size()<<'\n';
    for(i=0;i<dq.size();i++)
        cout<<dq[i]<<' ';
    return 0;
}

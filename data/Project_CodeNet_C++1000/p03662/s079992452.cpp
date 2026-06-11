#include <iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<bitset>
#define rep(i,j,n) for(int i=j;i<n;i++)
using namespace std;
#define int long long
struct edge{long long to,cost;};
typedef pair<int,int>P;
#define inf 1000000007
string alph("abcdefghijklmnopqrstuvwxyz");
vector<int> es[114514];
signed main(){
    int n;cin>>n;
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        es[a].push_back(b);
        es[b].push_back(a);
    }
    int d[114514];
    priority_queue<P,vector<P>,greater<P> >que;
    fill(d,d+n,inf);
    d[0]=0;
    que.push(P(0,0));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<es[v].size(); i++){
            int e=es[v][i];
            if(d[e]>d[v]+1){
                d[e]=d[v]+1;
                que.push(P(d[e],e));
            }
        }
    }
    int ds[114514];
    fill(ds,ds+n,inf);
    ds[n-1]=0;
    que.push(P(0,n-1));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(ds[v]<p.first)continue;
        for(int i=0;i<es[v].size(); i++){
            int e=es[v][i];
            if(ds[e]>ds[v]+1){
                ds[e]=ds[v]+1;
                que.push(P(ds[e],e));
            }
        }
    }
    int count=0;int h=0;
    rep(i,1,n-1){
        if(d[i]<=ds[i])count++;
        else h++;
    }
    if(count<=h)cout<<"Snuke"<<endl;
    else cout<<"Fennec"<<endl;
    return 0;
}

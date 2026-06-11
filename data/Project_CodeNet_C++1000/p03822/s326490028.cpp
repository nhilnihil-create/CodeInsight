#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
struct Node{
    int no;
    int par;
    int dist=0;
    vector<Node*> child;
    void build(int i){
        no=i;
        par=i;dist=0;
    }
};
struct Tree{
    int n;
    vector<Node> node;
    Tree(int k){
        n=k;
        node.resize(n+1);
        for(int i=1;i<=n;++i){
            node[i].build(i);
        }
    }
    void input(int k){
        for(int i=0;i<k;++i){
            int a,b;cin>>a;b=i+2;
            node[a].child.push_back(&node[b]);
            node[b].child.push_back(&node[a]);
        }
    }
    void BFS(int s){
        rep1(i,n){
            node[i].build(i);
        }
        queue<Node> que;
        que.push(node[s]);
        while(!que.empty()){
            Node buf=que.front();que.pop();
            int num=buf.child.size();
            for(int i=0;i<num;++i){
                if(buf.child[i]->no!=buf.par){
                    buf.child[i]->par=buf.no;
                    //buf.child[i]->dist=buf.dist+1;
                    que.push(*buf.child[i]);
                }
            }
        }
    }
    void DFS(Node& node){
        if(node.child.size()==1&&node.par!=node.no){
            node.dist=1;
            return;
        }
        else{
            int num=node.child.size();
            vector<int> koho;
            for(int i=0;i<num;++i){
                if(node.child[i]->no!=node.par){
                    DFS(*node.child[i]);
                    koho.push_back(node.child[i]->dist);
                }
            }
            sort(koho.begin(),koho.end());
            num=koho.size();
            int nxt=-1;
            rep(i,num){
                nxt=max(nxt,koho[i]+num-i);
            }
            node.dist=nxt;
        }
    }
    void solve(){
        BFS(1);
        DFS(node[1]);
        cout<<node[1].dist-1<<"\n";
    }
};
signed main(){
    int n;cin>>n;
    Tree tree(n);
    tree.input(n-1);
    tree.solve();
    return 0;
}

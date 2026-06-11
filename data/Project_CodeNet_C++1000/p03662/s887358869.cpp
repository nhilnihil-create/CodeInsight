#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010;
const double EPS=1e-9;
int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,-1,0,0};
vector<int> G[100010];
int d1[100010],d2[100010];
void dfs1(int i,int d){
    d1[i]=d;
    for(auto e:G[i]){
        if(d1[e]==INF){
            dfs1(e,d+1);
        }
    }
}
void dfs2(int i,int d){
    d2[i]=d;
    for(auto e:G[i]){
        if(d2[e]==INF){
            dfs2(e,d+1);
        }
    }
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<n;i++)d1[i]=INF,d2[i]=INF;
    dfs1(0,0);
    dfs2(n-1,0);
    int fc=0,sc=0;
    for(int i=0;i<n;i++){
        if(d1[i]<=d2[i]){
            fc++;
        }else{
            sc++;
        }
    }
    if(fc>sc){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
}


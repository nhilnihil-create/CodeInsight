#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    int N,M;cin>>N>>M;
    vector<vector<int>> graph(N);
    REP(i,M){
        int a,b; cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> f,b;
    vector<bool> used(N,false);
    bool judge=false;
    f.push_back(0);
    b.push_back(graph[0][0]);
    used[0]=used[graph[0][0]]=true;
    while(!judge){
        judge=true;
        for(auto e:graph[f.back()]){
            if(!used[e]){
                judge=false;
                f.push_back(e);
                used[e]=true;
                break;
            }
        }
        if(!judge) continue;
        for(auto e:graph[b.back()]){
            if(!used[e]){
                judge=false;
                b.push_back(e);
                used[e]=true;
                break;
            }
        }
    }
    cout<<f.size()+b.size()<<endl;
    for(int i=f.size()-1;i>=0;--i){
        cout<<f[i]+1<<" ";
    }
    REP(i,b.size()){
        cout<<b[i]+1<<" \n"[i==b.size()-1];
    }
}

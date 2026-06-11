
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int N;
int A[100000];
vector<int> edge[100000];
bool used[100000];

LL DFS(int v){
    used[v]=true;
    if(edge[v].size()==1)return A[v];

    vector<LL> lift;
    REP(i,edge[v].size())if(!used[edge[v][i]])lift.push_back(DFS(edge[v][i]));
    REP(i,lift.size())if(lift[i]==-1)return -1;

    LL sum = 0;
    REP(i,lift.size())sum+=lift[i];
    LL maxl = *max_element(ALL(lift));
    LL lower = (maxl*2 > sum ? maxl : (sum+1)/2);
    if(A[v]<lower||A[v]>sum)return -1;

    return 2*A[v]-sum;
}


int main(){
    cin>>N;
    REP(i,N)cin>>A[i];

    REP(i,N-1){
        int a,b;cin>>a>>b;
        edge[--a].push_back(--b);
        edge[b].push_back(a);
    }
    fill_n(used,N,false);

    REP(i,N){
        if(edge[i].size()>1){
            if(DFS(i)==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            return 0;
        }
    }
    if(A[0]==A[1])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}
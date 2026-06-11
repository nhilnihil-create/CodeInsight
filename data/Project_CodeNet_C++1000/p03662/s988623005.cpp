#include <bits/stdc++.h>

using namespace std;
#define ref(i,n) for(int i=0;i<n;i++)
int a,b,n,used[100001],con[100001];

vector<int> v[100001],vv;

int dfs(int x){
    vv.push_back(x);
    used[x]=1;

    if(x==n) return 1;
    ref(i,v[x].size()){
        if(used[v[x][i]])continue;
        if(dfs(v[x][i])==1) return 1;
    }

    vv.pop_back();
    return 0;
}

int sea(int x,int t){

    ref(i,v[x].size()){

        if(con[v[x][i]]!=0)continue;
        con[v[x][i]]=t;
        sea(v[x][i],t);
    }

    return 0;

}


int main()
{
    cin>>n;
    ref(i,n-1){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    ref(i,(vv.size()+1)/2) con[vv[i]]=1;
    con[n]=-1;
    sea(n,-1);
    int ss=0;
    ref(i,n) if(con[i+1]==-1) ss++;



    if(n>2*ss) cout<<"Fennec";
    else cout<<"Snuke";
    return 0;
}

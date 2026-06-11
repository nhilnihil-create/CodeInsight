#include<bits/stdc++.h>
using namespace std;

vector<int> ed[100001];

int dfs(int node,int p){


int ans=0;


int i;
for(i=0;i<ed[node].size();i++){

    int x=ed[node][i];
    if(x==p)
        continue;
    int u=1+dfs(x,node);
    ans=ans^u;



}

return ans;



}


int main(){
int n;
cin>>n;
int i;
for(i=1;i<n;i++)
{

    int x,y;
    cin>>x>>y;
    ed[x].push_back(y);
    ed[y].push_back(x);



}

int g=dfs(1,0);

if(g)
    cout<<"Alice"<<endl;
else
    cout<<"Bob"<<endl;



return 0;
}

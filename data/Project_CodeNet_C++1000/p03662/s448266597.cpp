#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> to[100010];
int kyori[2][100010]={};

void dfs(int i,int par,int j){
    for(int x:to[i]){
        if(x!=par){
            kyori[j][x]=kyori[j][i]+1;
            dfs(x,i,j);
        }
    }
    return;
}

int main(void){
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(1,0,0);
    dfs(n,0,1);
    int k0=0,k1=0;
    for(int i=1;i<=n;i++){
        if(kyori[0][i]<=kyori[1][i]){
            k0++;
        }
        else k1++;
    }
    if(k0>k1) cout<<"Fennec"<<endl;
    else cout<<"Snuke"<<endl;
}
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int MAX = 2001;
const int MOD = 1000000007;
 
 
vector<int> h[100001];
int used[100001]={};


 
signed main(){
    int n,m;
    cin>>n>>m;
    
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        
   
        h[u-1].push_back(v-1);
        h[v-1].push_back(u-1);
    }
    int t=0,count,t0,c[3]={};
    queue<int> hasi;
    
    while(true){
        while(t<n&&used[t]!=0)t++;
        if(t==n)break;
        count=0;
        hasi.push(t);
        used[t]=1;
        while(!hasi.empty()){
            t0=hasi.front();
            hasi.pop();
            for(int i=0;i<h[t0].size();i++){
                if(used[h[t0][i]]==used[t0])count=1;
                if(used[h[t0][i]]==0){
                    used[h[t0][i]]=-1*used[t0];
                    hasi.push(h[t0][i]);
                }
                
            }
           
        }
         if(t==t0)c[2]++;
            else c[count]++;


    }
    cout<<(c[0]+c[1])*(c[0]+c[1])+c[0]*c[0]+2*c[2]*n-c[2]*c[2];
    return 0;
}
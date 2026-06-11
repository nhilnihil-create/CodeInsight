#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<utility>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<iterator>
#include<map>
#include<limits>
#include<iomanip>
#include<ctime>
#include<cmath>
 
const int INF=2147483647;
const long long MOD=1e9+7;
 
using namespace std;




int main(){
    int n,m;
    cin>>n>>m;
    
    
    
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);
    vector<int> cols(n+1,-1);
    vector<int> preds(n+1,0);
    
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    long long  isoCt=0, bpct=0, nbpct=0;

    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            long long ect(0), vct(0);
            queue<int> q;
            q.push(i);
            cols[i]=0;
            bool isBp=true;
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                visited[cur]=true;
                vct++;
                
                for(int i:graph[cur]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                        preds[i]=cur;
                        cols[i]=!cols[cur];
                    }
                    else if(cols[i]==cols[cur]) isBp=false;
                    
                }
            }
            
            if(vct==1) isoCt++;
            else if(isBp) bpct++;
            else nbpct++;
        }
    }
    
    //cout<<bpct<<endl;
    cout<<2*n*isoCt-isoCt*isoCt+2*bpct*bpct+2*bpct*nbpct+nbpct*nbpct;
    
    
    return 0;
}
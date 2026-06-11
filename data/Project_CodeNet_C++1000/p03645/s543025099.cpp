#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
vector<int> to[200005];
const int MAX=1000000000;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    vector<int> dist(200005,MAX);
    dist[0]=0;
    while(q.size()!=0){
        int c=q.front();q.pop();
        for(int item:to[c]){
            if(dist[item]==MAX){
                dist[item]=dist[c]+1;
                q.push(item);
            }
        }        
    }
    string ans;
    if(dist[n-1]==2){
        ans="POSSIBLE";
    }else{
        ans="IMPOSSIBLE";
    }
    cout<<ans<<endl;
    return 0;
}
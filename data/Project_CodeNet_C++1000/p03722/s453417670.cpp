#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
struct edge {int from,to,cost;};

signed main() {
int n,m;
cin>>n>>m;
edge es[m];

for(int i=0;i<m;i++){
    cin>>es[i].from>>es[i].to>>es[i].cost;
    (es[i].from)--;(es[i].to)--;
}
int d[n]={};for(int i=1;i<n;i++)d[i]=-1*MOD*MOD;
bool used[n]={};
used[n-1]=true;
bool update=true;
while(update){
    update=false;
    for(int i=0;i<m;i++)if(used[es[i].to]&&(!used[es[i].from])){
        used[es[i].from]=true;
        update=true;
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(used[es[j].to]&&d[es[j].to]<d[es[j].from]+es[j].cost){
            d[es[j].to]=d[es[j].from]+es[j].cost;
            if(i==n-1){
                cout<<"inf";
                return 0;
            }
        }
    }
}

cout<<d[n-1];



return 0;
}

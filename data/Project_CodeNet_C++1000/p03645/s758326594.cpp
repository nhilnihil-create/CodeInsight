#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL n,m, minx=1e9, maxx=0, miny=1e9, maxy=0;
int a,b;
bool valid=false;
bool connect1[300001];
bool connectn[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(a==1){
            connect1[b]=true;
        }
        if(b==n){
            connectn[a]=true;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(connect1[i] && connectn[i]){
            valid=true;
        }
    }
    if(valid){
        cout<<"POSSIBLE"<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    bool a1[n+1]={};
    bool an[n+1]={};
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x==1)a1[y]=true;
        if(y==n)an[x]=true;
        }
    bool flag=false;
    for(int i=0;i<n;i++){
        if(a1[i]&&an[i]){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
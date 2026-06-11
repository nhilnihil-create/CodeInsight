#include<bits/stdc++.h>
using namespace std;
int main(){
int n,x;
int defrag;
int defragg;
bool dis[10]= {};
cin>>n>>x;
for(int i=0;i<x;i++){
    cin>>defrag;
    dis[defrag]=1;
}
for(int i=n;i;i++){
    defrag=i;
    int o=0;
    while(defrag>0){
        defragg=defrag%10;
        defrag/=10;
        if(dis[defragg]==1){
            o=1;
            break;
        }
    }
    if(o==1){
        continue;
    }
    else{
        cout<<i;
        break;
    }
}
}
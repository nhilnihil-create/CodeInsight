#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,a;
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            a=i*m;
            a+=j*n;
            a-=j*i*2;
            if(k==a){
                cout<<"Yes"<<endl;
                return(0);
            }
        }
    }
    cout<<"No"<<endl;
    return(0);
}
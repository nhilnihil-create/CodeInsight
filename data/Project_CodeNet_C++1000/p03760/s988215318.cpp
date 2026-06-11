#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    string o,e;
    cin>>o>>e;
    for(int i=2;i<=o.size()+e.size()+1;i++){
        if(i%2==0){
            cout<<o[i/2-1];
        }
        else{
            cout<<e[i/2-1];
        }
    }
    cout<<endl;
    return(0);
}
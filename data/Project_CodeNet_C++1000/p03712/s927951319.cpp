#include<bits/stdc++.h>
using namespace std;

int N,K,i;
string a;


int main(){
    cin>>N>>K;
    for(i=1;i<=K+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(i=1;i<=N;i++){
        cin>>a;
        cout<<"#"<<a<<"#"<<endl;
    }
    for(i=1;i<=K+2;i++){
        cout<<"#";
    }
}
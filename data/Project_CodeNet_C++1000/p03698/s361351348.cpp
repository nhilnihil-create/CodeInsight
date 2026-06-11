#include<bits/stdc++.h>
using namespace std;

int K,i,x=0,j;
string N;


int main(){
    cin>>N;
    for(i=0;i<=N.length()-1;i++){
        for(j=0;j<=N.length()-1;j++){
            if(N[i]==N[j]&&i!=j){
                x=x+1;
            }
        }
    } 
    if(x>0){
        cout<<"no";
    }
    else{
        cout<<"yes";
    }
}
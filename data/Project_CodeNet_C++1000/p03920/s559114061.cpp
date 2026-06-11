#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;cin>>N;
    int j,k;
    for(int i=1;i<=10000;i++){
        j=i*(i+1)/2;
        if(j>=N){
            k=i;
            break;
        }
    }
    int l=j-N;
    for(int i=1;i<=k;i++){
        if(i!=l) cout<<i<<endl;
    }
    
}



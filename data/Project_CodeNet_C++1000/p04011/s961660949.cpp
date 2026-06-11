#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K,x,y;
    cin>>N>>K>>x>>y;
    if(N>K){
        cout<<(K*x+y*(N-K))<<endl;
    }
    else{
        cout<<N*x<<endl;
    }





    return 0;
}

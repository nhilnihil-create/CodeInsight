#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,M;
    cin>>N>>M;
    M=M*2;
    vector<int>toshi(N);
    vector<int>douro(M);
    for(int i=0; i<M; i++){
            cin>>douro[i];
            toshi[douro[i]-1]++;
    }
    for(int i=0; i<N; i++){
            cout<<toshi[i]<<endl;
    }
}
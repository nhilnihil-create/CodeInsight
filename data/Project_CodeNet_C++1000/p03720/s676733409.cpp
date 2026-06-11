#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int R[55]= {0};
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a;
        cin>>b;
        R[a] += 1;
        R[b] += 1;
    }
    for(int i=1;i<=N;i++){
        cout<<R[i]<<endl;
    }
}
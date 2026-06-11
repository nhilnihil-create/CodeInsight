#include<iostream>
using namespace std;
int main(void){
    int N,T;
    cin>>N>>T;
    int t[200000]={0};
    for(int i(0);i<N;i++){
        cin>>t[i];
    }
    long long total_time(0);
    total_time = (long long)T*N;
    for(int i(0);i<N-1;i++){
        if(t[i+1]-t[i]<T)total_time -= T - t[i+1] + t[i];
    }
    cout<<total_time<<endl;
    return 0;
}
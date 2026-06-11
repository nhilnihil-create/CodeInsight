#include<iostream>
#include<algorithm>
using namespace std;
int N,C,K,ans;
int main(){
    cin>>N>>C>>K;
    int T[N];
    for(int i=0;i<N;i++)cin>>T[i];
    sort(T,T+N);
    for(int i=0,M=0;i<N;i++)if(T[M]+K<T[i]||i-M+1>C)ans++,M=i;
    cout<<ans+1<<endl;
    return 0;
}
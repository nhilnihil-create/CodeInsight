#include<iostream>
using namespace std;
int N,M,a,b;
int main(){
    cin>>N>>M;
    int cnt[N];
    for(int i=0;i<N;i++)cnt[i]=0;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        cnt[a-1]++,cnt[b-1]++;
    }
    for(int i=0;i<N;i++)if(cnt[i]%2){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
    return 0;
}
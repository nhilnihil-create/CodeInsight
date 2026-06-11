#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int l[N];
    for(int i=1;i<=N;++i)cin>>l[i];

    sort(l+1,l+N+1,greater<int>());
    int sum=0;
        for(int i=1;i<=K;++i){
            sum+=l[i];
        }
    cout<<sum;
}
#include<bits/stdc++.h>
using namespace std;
long long Q,H,S,D,N,ans;
int main(){
    cin>>Q>>H>>S>>D>>N;
    ans=(N%2==0)?(min(min(min(Q*8,H*4),S*2),D)*N/2):(min(min(Q*4,H*2),S)+min(min(min(Q*8,H*4),S*2),D)*(N-1)/2);
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;cin>>N>>M;
    vector<int>ans(N,0);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        ans[a-1]++;
        ans[b-1]++;
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
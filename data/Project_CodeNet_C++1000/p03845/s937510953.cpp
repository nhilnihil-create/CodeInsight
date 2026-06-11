#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;cin>>N;
    int T[N];
    for(int i=0;i<N;i++){
        cin>>T[i];
    }
    int M;cin>>M;
    int P[M],X[M];
    for(int i=0;i<M;i++){
        cin>>P[i]>>X[i];
    }
    for(int i=0;i<M;i++){
        int ans=0;
        for(int l=0;l<N;l++){
            if(l==P[i]-1){
                ans+=X[i];
            }
            else{
                ans+=T[l];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
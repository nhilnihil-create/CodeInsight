#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N,M;cin>>N>>M;
    long long A[N],B[N];
    for(long long i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    long long C[M],D[M];
    for(long long i=0;i<M;i++){
        cin>>C[i]>>D[i];
    }
    for(long long i=0;i<N;i++){
        long long ans=-2;
        long long dist=4*pow(10,8)+1;
        for(long long j=0;j<M;j++){
            if(dist>abs(A[i]-C[j])+abs(B[i]-D[j])){
                dist=abs(A[i]-C[j])+abs(B[i]-D[j]);
                ans=j+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

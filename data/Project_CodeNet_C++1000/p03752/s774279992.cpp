#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;


int main(){

    int N,K;
    cin>>N>>K;

    long long A[N];

    rep(i,N)cin>>A[i];

    long long buildings[N];
    buildings[0]=1;
    rep(i,N-1)buildings[i+1]=buildings[i]*2;

    long long ans=INF;

    vector<int>v(N);
    for(int i=0;i<(1<<N);i++){
        bool seen[N]={};

        rep(k,N)if(buildings[k]&i)seen[k]=true;

        long long now=0;
        long long total=0;
        int see=0;

        for(int l=0;l<N;l++)
        {
            
            if(seen[l]){
                see++;
                if(now>=A[l]){
                    now++;
                    total+=now-A[l];
                }
                else{
                    now=max(A[l],now);
                }
            }
            else{
                now=max(A[l],now);
            }
        }

        if(see>=K){
            if(ans>=total){
            ans=total;
                /*
                rep(l,N){
                    if(seen[l])v[l]=1;
                    else{
                    v[l]=0;
                    }
                }
                */
            }
        
        }

    }
    
    cout<<ans<<endl;
    //rep(i,N)cout<<v[i]<<" ";
    //cout<<endl;
    return 0;

}
/*


*/

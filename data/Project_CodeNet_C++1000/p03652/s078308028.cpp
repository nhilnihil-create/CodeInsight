#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003;

int main(){
        
    int N,M;cin>>N>>M;
    int A[N+1][M+1],now[N+1];//now[i]はiは何番目にいるかをみてる
    bool B[M+1];//B[i]=1ならまだiは使える
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M+1;j++){
            if(i&&j) cin>>A[i][j];
            else A[i][j]=-1;
            B[j]=1;
        }
        now[i]=1;
    }
    
    int ans=N;
    
    for(int j=0;j<M;j++){
        vector<int> cnt(M+1);
        for(int i=0;i<=M;i++){
            cnt[i]=0;
        }
        for(int i=1;i<=N;i++){
            while(B[A[i][now[i]]]==0){
                now[i]++;
            }
            cnt[A[i][now[i]]]++;
        }
        int Q=0,p=0;
        for(int i=1;i<=M;i++){
            if(cnt[i]>Q){
                Q=cnt[i];
                p=i;
            }
        }
        ans=min(ans,Q);
        B[p]=0;
    }
    /*for(int i=0;i<=N;i++){
        if(B[i]) cout<<i<<endl;
    }*/
    cout<<ans<<endl;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200001,INF=1<<30;

int main(){

    int N,K;cin>>N>>K;
    vector<int> A(N),B;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    for(int i=0;i<N;i++){
        if(A[i]<K) B.push_back(A[i]);
    }
    int M=int(B.size());
    if(M==0) cout<<0<<endl;
    else{
        
        vector<vector<int>> dp(K,vector<int>(2,0));
        dp[0][1]=1;
        bool ok=false;
        
        for(int i=0;i<M;i++){
            if(i==0){
                for(int j=0;j<=K-1;j++){
                    dp[j][i%2]=dp[j][(i+1)%2];
                }
            }else{
                for(int j=0;j<=K-1;j++){
                    if(j-B[i]<0) dp[j][i%2]=dp[j][(i+1)%2];
                    else if(dp[j-B[i]][(i+1)%2]) dp[j][i%2]=1;
                    else dp[j][i%2]=0;
                }
            }
        }
        
        for(int j=K-B[0];j<=K-1;j++){
            if(dp[j][(M-1)%2]) ok=true;
        }
        
        if(ok) cout<<0<<endl;
        else{
            vector<vector<int>> dp(K,vector<int>(2,0));
            dp[0][1]=1;
            bool ok=false;
            
            for(int i=0;i<M;i++){
                if(i==M-1){
                    for(int j=0;j<=K-1;j++){
                        dp[j][i%2]=dp[j][(i+1)%2];
                    }
                }else{
                    for(int j=0;j<=K-1;j++){
                        if(j-B[i]<0) dp[j][i%2]=dp[j][(i+1)%2];
                        else if(dp[j-B[i]][(i+1)%2]) dp[j][i%2]=1;
                        else dp[j][i%2]=0;
                    }
                }
            }
            
            for(int j=K-B[M-1];j<=K-1;j++){
                if(dp[j][(M-1)%2]) ok=true;
            }
            
            if(!ok) cout<<M<<endl;
            else{
                int left=0,right=M-1;
                while(right-left>1){
                    int mid=(left+right)/2;
                    bool ok=false;
                    vector<vector<int>> dp(K,vector<int>(2,0));
                    dp[0][1]=1;
                    
                    for(int i=0;i<M;i++){
                        if(i==mid){
                            for(int j=0;j<=K-1;j++){
                                dp[j][i%2]=dp[j][(i+1)%2];
                            }
                        }else{
                            for(int j=0;j<=K-1;j++){
                                if(j-B[i]<0) dp[j][i%2]=dp[j][(i+1)%2];
                                else if(dp[j-B[i]][(i+1)%2]) dp[j][i%2]=1;
                                else dp[j][i%2]=0;
                            }
                        }
                    }
                    
                    for(int j=K-A[mid];j<=K-1;j++){
                        if(dp[j][(M-1)%2]) ok=true;
                    }
                    
                    if(ok) right=mid;
                    else left=mid;
                    //cout<<left<<" "<<right<<endl;
                }
                
                cout<<left+1<<endl;
            }
        }
    }
}


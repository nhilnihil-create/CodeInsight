#include<iostream>
using namespace std;
const int C_MAX=40*100*2;
const int AB_MAX=40*10;
const int INF=C_MAX;

int main(){
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    int a[N], b[N], c[N];
    int ans;

    for(int i=0; i<N; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp[N+1][AB_MAX+1][AB_MAX+1];

    for(int i=0; i<N+1; i++){
        for(int ca=0; ca<=AB_MAX; ca++){
            for(int cb=0; cb<=AB_MAX; cb++){
                //cout << "i ca cb= " << i << " " << ca << " " << cb << endl;
                dp[i][ca][cb]=INF;
            }
        }
    }

    dp[0][0][0]=0;

    for(int i=0; i<N; i++){
        for(int ca=0; ca<=AB_MAX; ca++){
            for(int cb=0; cb<=AB_MAX; cb++){
                if(dp[i][ca][cb]==INF){
                    continue;
                }
                //cout << "i ca cb " << i << " " << ca << " " << cb << endl; 
                dp[i+1][ca][cb]=min(dp[i+1][ca][cb],  dp[i][ca][cb]);
                dp[i+1][ca+a[i]][cb+b[i]]=min(dp[i+1][ca+a[i]][cb+b[i]],  dp[i][ca][cb]+c[i]);
                //cout << "i+1 ca+a cb+b dp " << i+1 << " " << ca+a[i] << " " << ca+b[i] << " " << dp[i+1][ca+a[i]][cb+b[i]] << endl;
            }
        }
    }

    ans=INF;
    for(int ca=1; ca<=AB_MAX; ca++){
        for(int cb=1; cb<=AB_MAX; cb++){
            if( ca*Mb == cb*Ma ){
                    //cout << "met ca cb " << ca << " " << cb << endl;
                    ans=min(ans,dp[N][ca][cb]);
            }
        }
    }

    if( ans==INF ){
        ans=-1;
    }

    cout << ans << endl;
//*/
    return 0;
}
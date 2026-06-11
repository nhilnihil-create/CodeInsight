//arc070d.cpp
#include<iostream>
#include<vector>
using namespace std;

int MOD = 10007;

int main(){
    int ans=0;
    int N,K;
    cin >> N >> K;
    int a_sub;
    vector<int> a;
    int i,j;
    a.push_back(0);
    for(i=1; i<=N; i++){
        cin >> a_sub;
        if(a_sub<K){
            a.push_back(a_sub);
        }
    }
    int M=a.size()-1;
    if(M<=0){
        cout << ans << endl;
        return 0;
    }
    int dp[2][2*K+1], dp_rev[K+1];
    dp[0][0]=1;
    for(j=1; j<=2*K; j++){
        dp[0][j]=0;
    }
    for(i=1; i<=M; i++){
        for(j=0; j<=2*K; j++){
            if(j-a[i]<0){
                dp[i%2][j]=dp[!(i%2)][j];
            }else{
                dp[i%2][j]=dp[!(i%2)][j]+dp[!(i%2)][j-a[i]];
                dp[i%2][j]%=MOD;
            }
        }
    }
    for(i=1; i<=M; i++){
        for(j=0; j<=K; j++){
            if(j-a[i]<0){
                dp_rev[j]=dp[M%2][j];
            }else{
                dp_rev[j]=dp[M%2][j]+(MOD-dp_rev[j-a[i]]);
                dp_rev[j]%=MOD;
            }
        }
        for(j=K; j<K+a[i]; j++){
            if((dp[M%2][j]>0)&&(dp_rev[j-a[i]]>0)){
                break;
            }
        }
        if(j>=K+a[i]){
            ans++;
        }
    }
    cout << ans <<endl;
    system("pause");
    return 0;
}
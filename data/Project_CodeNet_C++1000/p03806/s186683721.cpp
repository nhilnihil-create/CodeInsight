#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli dp[500][500];

void func(long long N, long long M_a, long long M_b, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){
    REP(i,0,500)REP(j,0,500)dp[i][j]=INF;

    dp[0][0]=0;
    REP(i,0,N){
        lli aa = a[i];
        lli bb = b[i];

        for(lli j=400;j>=0;j--){
            for(lli k=400;k>=0;k--){
                dp[j+aa][k+bb] = min(dp[j+aa][k+bb],dp[j][k]+c[i]);
            }            
        }
    }

    lli ans = INF;
    REP(i,1,500){
        lli aa = i*M_a;
        lli bb = i*M_b;
        if(aa>480 || bb>480)break;
        ans = min(ans,dp[aa][bb]);
    }
    if(ans == INF)cout<<-1<<endl;
    else cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M_a;
    scanf("%lld",&M_a);
    long long M_b;
    scanf("%lld",&M_b);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    std::vector<long long> c(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
    }
    func(N, M_a, M_b, std::move(a), std::move(b), std::move(c));
    return 0;
}

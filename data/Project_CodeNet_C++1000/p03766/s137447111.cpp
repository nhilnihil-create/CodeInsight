#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl


signed main(void){
    int N;
    const int MEM=1114514;
    int dp[MEM],dps[MEM]={};
    cin >> N;
    dp[0]=1;dps[1]=1;
    OREP(i,N){
        if(i==1){dp[1]=1;dps[2]=2;continue;}
        dp[i]=dps[i-2]+dp[i-1];
        dp[i]%=MOD;
        dps[i+1]=dps[i]+dp[i];
        dps[i]%=MOD;
    }
    
    int Ans=0,num=0;
    REP(i,N){
        if(i<=N-3){
            num=N*(N-2);num%=MOD;
            num+=i+3;num%=MOD;
        }else if(i==N-2){
            num=N*(N-1);num%=MOD;
        }else if(i==N-1){
            num=N;num%=MOD;
        }
        
        
        num*=dp[i];num%=MOD;
        Ans+=num;Ans%=MOD;
    }
    cout << Ans << endl;
    return 0;
}


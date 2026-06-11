#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "-1" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N,L,Q;
    int a[114514],b[114514];
    vector<int> x;
    cin >> N;
    int y;
    REP(i,N){cin >> y;y--;x.push_back(y);}
    cin >> L >> Q;
    REP(i,Q){cin >> a[i] >> b[i];a[i]--;b[i]--;if(b[i]<a[i])swap(a[i],b[i]);}
    
    int dp[20][114514];
    REP(i,N){
        dp[0][i]=-1+(int)(upper_bound(x.begin(),x.end(),x[i]+L)-x.begin());
    }
    for(int k=0;(1<<k)<N;k++){
        REP(i,N){
            dp[k+1][i]=dp[k][dp[k][i]];
        }
    }
    
    REP(j,Q){
        int P=a[j],R=b[j];
        int l=0,r=N,mid;
        while(abs(r-l)>1){
            mid=(l+r)/2;
            int now=P;
            int m=mid,k=0;
            while(m>0){
                if(m%2==1){
                    now=dp[k][now];
                }
                k++;
                m/=2;
            }
            if(now>=R){
                r=mid;
            }else{
                l=mid;
            }
        }
        cout << l+1<< endl;
    }
    
    return 0;
}


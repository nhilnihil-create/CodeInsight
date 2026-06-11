#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define zero_pad(num) setfill('0') << std::right << setw(num)
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int A,B,C,D,E,F;cin>>A>>B>>C>>D>>E>>F;
    double ansper=0;
    int answs=0;
    int anss=0;
    REP(w,31){
        REP(x,31){
            REP(y,F/C+1){
                REP(z,F/D+1){
                    double wsum=100*(A*w+B*x);
                    double ssum=C*y+D*z;
                    if(F>=wsum+ssum){
                        double nowp=100*ssum/(wsum+ssum);
                        if(nowp>ansper&&E*wsum>=ssum*100){
                            ansper=nowp;
                            answs=wsum+ssum;
                            anss=ssum;
                        }
                    }
                }
            }
        }
    }
    if(ansper==0)answs=100*A;
    cout<<answs<<" "<<anss<<endl;
}
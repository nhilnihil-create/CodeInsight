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
const int N_MAX=1e5;

signed main(){
    int N;cin>>N;
    vector<int>A(N);
    REP(i,N)cin>>A[i];
    sort(A.begin(),A.end());
    bool ok=true;
    if(A[N-1]-A[0]>=2)ok=false;
    if(ok){
        int count=0;
        REP(i,N)if(A[i]==A[0])count++;
        if(count==N){
            if(A[0]!=N-1&&A[0]*2>N)ok=false;
        }
        else{
            if(count>=A[N-1]||2*A[N-1]>N+count)ok=false;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
}

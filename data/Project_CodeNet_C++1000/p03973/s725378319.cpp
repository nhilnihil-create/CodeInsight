#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int main(){

    int N;cin>>N;
    LL A[N];REP(i,N)cin>>A[i];
    LL ans=0;
    LL mm = 0;
    REP(i,N){
        ans+=A[i]/(mm+1);
        if(A[i]%(mm+1)==0)ans--;
        if(mm+1==A[i])mm++;
        if(i==0)mm=1;
    }
    cout<<ans<<endl;


    return 0;
}
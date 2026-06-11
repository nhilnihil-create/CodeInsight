#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    constexpr int MAX_A=10001;
    int N,K;
    cin>>N>>K;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    vector<bitset<MAX_A+1>> dpl(N+1),dpr(N+1);
    dpl[0]=1;
    dpr[N]=1;
    REP(i,N){
        dpl[i+1]=(dpl[i]<<a[i])|dpl[i];
        dpr[N-i-1]=(dpr[N-i]<<a[N-i-1])|dpr[N-i];
    }
    int ans=N;
    REP(i,N){
        if(a[i]>=K){
            ans--;
            continue;
        }
        int suml[MAX_A+1]={},sumr[MAX_A+1]={};
        REP(j,K){
            suml[j+1]=suml[j]+dpl[i][j];
            sumr[j+1]=sumr[j]+dpr[i+1][j];
        }
        REP(t,K) if(dpl[i][t]){
            if(t<K-a[i]){
                if(sumr[K-t]-sumr[K-t-a[i]]){
                    ans--;
                    break;
                }
            }
            else{
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N;cin>>N;
    vector<ll> a(N),t(N);
    REP(i,N)cin>>a[i]>>t[i];
    ll na=a[0];
    ll nt=t[0];
    FOR(i,1,N){
        if(na*t[i]==nt*a[i])continue;
        else{
            ll u=(na%a[i]==0?na/a[i]:na/a[i]+1);
            ll v=(nt%t[i]==0?nt/t[i]:nt/t[i]+1);
            ll w=max(u,v);
            na=w*a[i];
            nt=w*t[i];
        }
    }
    cout<<na+nt<<endl;
    return 0;
}
#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N,L;
    cin>>N>>L;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    vector<ll> S(N+1);
    REP(i,N) S[i+1]=S[i]+a[i];
    vector<int> ans1,ans2;
    REP(i,N-1){
        if(a[i]+a[i+1]>=L){
            cout<<"Possible"<<endl;
            REP(j,i) cout<<j+1<<endl;
            for(int j=N-1;j>i;--j) cout<<j<<endl;
            return 0;
        }
    }
    cout<<"Impossible"<<endl;
}

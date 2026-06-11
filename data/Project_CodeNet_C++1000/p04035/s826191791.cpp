#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;

int main(){
    int N,L;cin>>N>>L;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    REP(i,N-1){
        if(a[i]+a[i+1]>=L){
            cout<<"Possible"<<endl;
            REP(k,i){
                cout<<k+1<<endl;
            }
            for(int k=N-2;k>=i+1;--k){
                cout<<k+1<<endl;
            }
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<"Impossible"<<endl;
}

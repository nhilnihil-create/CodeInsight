#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<int> p(N);
    REP(i, N) cin >> p[i],p[i]--;
    vector<int> a(N),b(N);
    REP(i,N){
        a[i]=20000*(N-i);
        b[i]=20000*(i+1);
    }
    REP(i,N){
        a[p[i]]+=i;
    }
    REP(i,N) cout<<b[i]<<" \n"[i+1==N];
    REP(i,N) cout<<a[i]<<" \n"[i+1==N];
}

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e20;

int myd(int x,int y){
    if(x%y==0)return x/y;
    else return x/y+1;
}

signed main(){
    int N;cin>>N;
    vector<int>A(N);
    REP(i,N)cin>>A[i];
    sort(A.begin(),A.end());
    int count=0;
    REP(i,N-1){
        if(A[i]==A[i+1])count++;
    }
    cout<<N-2*myd(count,2)<<endl;
}
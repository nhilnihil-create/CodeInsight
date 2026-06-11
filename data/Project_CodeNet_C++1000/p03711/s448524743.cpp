#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX=3000;

int mydiv(int x,int y){
    if(x%y==0)return x/y;
    else return x/y+1;
}

signed main(){
    int A[12]={0,2,0,1,0,1,0,0,1,0,1,0};
    int x,y;cin>>x>>y;x--;y--;
    cout<<(A[x]==A[y]?"Yes":"No")<<endl;
}